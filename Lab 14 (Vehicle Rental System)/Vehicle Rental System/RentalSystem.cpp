#include "RentalSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

// ============================================================
//  Constructor / Destructor
// ============================================================
RentalSystem::RentalSystem()
    : nextVehicleID(1), nextCustomerID(1), nextRentalID(1),
      VEHICLES_FILE("vehicles.txt"),
      CUSTOMERS_FILE("customers.txt"),
      RENTALS_FILE("rentals.txt")
{
    loadAll();
}
// This is a range-based for loop used with pointers to deallocate dynamically allocated objects and prevent memory leaks.
RentalSystem::~RentalSystem() {
    saveAll();
    for (auto v : fleet)     delete v;
    for (auto c : customers) delete c;
    for (auto r : rentals)   delete r;
}

// ============================================================
//  Internal Helpers
// ============================================================
Vehicle* RentalSystem::findVehicle(int id) const {
    for (auto v : fleet)
        if (v->getID() == id) return v;
    return nullptr;
}

Customer* RentalSystem::findCustomer(int id) const {
    for (auto c : customers)
        if (c->getID() == id) return c;
    return nullptr;
}

Rental* RentalSystem::findRental(int id) const {
    for (auto r : rentals)
        if (r->getID() == id) return r;
    return nullptr;
}

// ============================================================
//  R1 Add Vehicles
// ============================================================
void RentalSystem::addCar(const string& model, double rate, int seats) {
    fleet.push_back(new Car(nextVehicleID++, model, rate, seats));
    saveVehicles();
    cout << "  [OK] Car added: " << model << "\n";
}

void RentalSystem::addMotorbike(const string& model, double rate, int cc) {
    fleet.push_back(new Motorbike(nextVehicleID++, model, rate, cc));
    saveVehicles();
    cout << "  [OK] Motorbike added: " << model << "\n";
}

void RentalSystem::addTruck(const string& model, double rate, double payload) {
    fleet.push_back(new Truck(nextVehicleID++, model, rate, payload));
    saveVehicles();
    cout << "  [OK] Truck added: " << model << "\n";
}

void RentalSystem::removeVehicle(int vehicleID) {
    // Step 1: Vehicle exist karta hai?
    Vehicle* veh = findVehicle(vehicleID);
    if (!veh) {
        cout << "  [ERROR] Vehicle ID " << vehicleID << " not found.\n";
        return;
    }

    // Step 2: Rented vehicle remove nahi kar sakte
    if (!veh->isAvailable()) {
        cout << "  [ERROR] Vehicle '" << veh->getMakeModel()
             << "' abhi rented hai. Pehle return karwao, phir remove karo.\n";
        return;
    }

    // Step 3: Is vehicle ka koi active rental record to nahi?
    for (auto r : rentals) {
        if (r->getVehicle()->getID() == vehicleID && r->isActive()) {
            cout << "  [ERROR] Vehicle ka active rental record mojood hai.\n";
            return;
        }
    }

    // Step 4: Fleet vector se dhoondo aur remove karo
    string removedName = veh->getMakeModel();
    for (auto it = fleet.begin(); it != fleet.end(); ++it) {
        if ((*it)->getID() == vehicleID) {
            delete *it;         // memory free karo
            fleet.erase(it);    // vector se hata do
            break;
        }
    }

    saveVehicles();
    cout << "  [OK] Vehicle '" << removedName
         << "' (ID " << vehicleID << ") fleet se remove ho gaya.\n";
}

void RentalSystem::displayFleet() const {
    cout << "\n===== FLEET =====\n";
    if (fleet.empty()) { cout << "  No vehicles registered.\n"; return; }
    for (auto v : fleet) v->displayInfo();
}

// ============================================================
//  R2 Customer Registration
// ============================================================
void RentalSystem::registerCustomer(const string& name) {
    customers.push_back(new Customer(nextCustomerID++, name));
    saveCustomers();
    cout << "  [OK] Customer registered: " << name
         << " (ID " << nextCustomerID - 1 << ")\n";
}

void RentalSystem::displayCustomers() const {
    cout << "\n===== CUSTOMERS =====\n";
    if (customers.empty()) { cout << "  No customers registered.\n"; return; }
    for (auto c : customers) c->displayInfo();
}

// ============================================================
//  R3 Rent a Vehicle
// ============================================================
void RentalSystem::rentVehicle(int customerID, int vehicleID, int days) {
    Customer* cust = findCustomer(customerID);
    Vehicle*  veh  = findVehicle(vehicleID);

    if (!cust) {
        cout << "  [ERROR] Customer ID " << customerID << " not found.\n";
        return;
    }
    if (!veh) {
        cout << "  [ERROR] Vehicle ID " << vehicleID << " not found.\n";
        return;
    }
    if (cust->isRenting()) {
        cout << "  [ERROR] " << cust->getName() << " already has an active rental.\n";
        return;
    }
    if (!veh->isAvailable()) {
        cout << "  [ERROR] " << veh->getMakeModel() << " is currently rented out.\n";
        return;
    }
    if (days <= 0) {
        cout << "  [ERROR] Days must be >= 1.\n";
        return;
    }

    veh->setAvailable(false);
    cust->setRenting(true);

    Rental* r = new Rental(nextRentalID++, cust, veh, days);
    rentals.push_back(r);

    saveAll();
    cout << fixed << setprecision(2);
    cout << "  [OK] Rental #" << r->getID()
         << " created. Total Cost: Rs." << r->getCost() << "\n";
}

// ============================================================
//  R5 Return a Vehicle
// ============================================================
void RentalSystem::returnVehicle(int rentalID) {
    Rental* r = findRental(rentalID);

    if (!r) {
        cout << "  [ERROR] Rental ID " << rentalID << " not found.\n";
        return;
    }
    if (!r->isActive()) {
        cout << "  [ERROR] Rental #" << rentalID << " is already closed.\n";
        return;
    }

    r->getVehicle()->setAvailable(true);
    r->getCustomer()->setRenting(false);
    r->closeRental();

    saveAll();
    cout << "  [OK] Rental #" << rentalID << " closed. Vehicle returned.\n";
}

// ============================================================
//  R6 Print Summary
// ============================================================
void RentalSystem::printSummary() const {
    cout << "\n========== SUMMARY ==========\n";

    cout << "--- Active Rentals ---\n";
    bool anyActive = false;
    for (auto r : rentals)
        if (r->isActive()) { r->displayInfo(); anyActive = true; }
    if (!anyActive) cout << "  No active rentals.\n";

    int avail = 0, rented = 0;
    for (auto v : fleet)
        (v->isAvailable() ? avail : rented)++;

    cout << "--- Fleet Count ---\n";
    cout << "  Available : " << avail         << "\n";
    cout << "  Rented    : " << rented         << "\n";
    cout << "  Total     : " << fleet.size()   << "\n";
    cout << "==============================\n";
}

// ============================================================
//  File Handling — Save
// ============================================================
void RentalSystem::saveAll() const {
    saveVehicles();
    saveCustomers();
    saveRentals();
}

// Format: TYPE|ID|MODEL|RATE|AVAILABLE|EXTRA
void RentalSystem::saveVehicles() const {
    ofstream f(VEHICLES_FILE);
    if (!f) { cerr << "  [FILE ERROR] Cannot write " << VEHICLES_FILE << "\n"; return; }

    f << "# nextID=" << nextVehicleID << "\n";
    for (auto v : fleet) {
        f << v->getType() << "|"
          << v->getID()   << "|"
          << v->getMakeModel() << "|"
          << fixed << setprecision(2) << v->getDailyRate() << "|"
          << (v->isAvailable() ? 1 : 0) << "|";

        if (Car* c = dynamic_cast<Car*>(v))
            f << c->getSeats();
        else if (Motorbike* m = dynamic_cast<Motorbike*>(v))
            f << m->getEngineCC();
        else if (Truck* t = dynamic_cast<Truck*>(v))
            f << t->getPayload();
        f << "\n";
    }
}

// Format: ID|NAME|HAS_ACTIVE
void RentalSystem::saveCustomers() const {
    ofstream f(CUSTOMERS_FILE);
    if (!f) { cerr << "  [FILE ERROR] Cannot write " << CUSTOMERS_FILE << "\n"; return; }

    f << "# nextID=" << nextCustomerID << "\n";
    for (auto c : customers)
        f << c->getID() << "|"
          << c->getName() << "|"
          << (c->isRenting() ? 1 : 0) << "\n";
}

// Format: ID|CUST_ID|VEH_ID|DAYS|COST|ACTIVE
void RentalSystem::saveRentals() const {
    ofstream f(RENTALS_FILE);
    if (!f) { cerr << "  [FILE ERROR] Cannot write " << RENTALS_FILE << "\n"; return; }

    f << "# nextID=" << nextRentalID << "\n";
    for (auto r : rentals)
        f << r->getID()                << "|"
          << r->getCustomer()->getID() << "|"
          << r->getVehicle()->getID()  << "|"
          << r->getDays()              << "|"
          << fixed << setprecision(2) << r->getCost() << "|"
          << (r->isActive() ? 1 : 0)  << "\n";
}

// ============================================================
//  File Handling — Load
// ============================================================
void RentalSystem::loadAll() {
    loadVehicles();
    loadCustomers();
    loadRentals();
}

void RentalSystem::loadVehicles() {
    ifstream f(VEHICLES_FILE);
    if (!f) return;

    string line;
    while (getline(f, line)) {
        if (line.empty() || line[0] == '#') {
            if (line.find("nextID=") != string::npos)
                nextVehicleID = stoi(line.substr(line.find('=') + 1));
            continue;
        }
        istringstream ss(line);
        string type, model, extra;
        int id, avail;
        double rate;

        getline(ss, type,  '|');
        ss >> id;    ss.ignore();
        getline(ss, model, '|');
        ss >> rate;  ss.ignore();
        ss >> avail; ss.ignore();
        getline(ss, extra);

        Vehicle* v = nullptr;
        if      (type == "Car")       v = new Car      (id, model, rate, stoi(extra));
        else if (type == "Motorbike") v = new Motorbike(id, model, rate, stoi(extra));
        else if (type == "Truck")     v = new Truck    (id, model, rate, stod(extra));

        if (v) {
            v->setAvailable(avail == 1);
            fleet.push_back(v);
        }
    }
}

void RentalSystem::loadCustomers() {
    ifstream f(CUSTOMERS_FILE);
    if (!f) return;

    string line;
    while (getline(f, line)) {
        if (line.empty() || line[0] == '#') {
            if (line.find("nextID=") != string::npos)
                nextCustomerID = stoi(line.substr(line.find('=') + 1));
            continue;
        }
        istringstream ss(line);
        int id, active;
        string name;

        ss >> id; ss.ignore();
        getline(ss, name, '|');
        ss >> active;

        Customer* c = new Customer(id, name);
        c->setRenting(active == 1);
        customers.push_back(c);
    }
}

void RentalSystem::loadRentals() {
    ifstream f(RENTALS_FILE);
    if (!f) return;

    string line;
    while (getline(f, line)) {
        if (line.empty() || line[0] == '#') {
            if (line.find("nextID=") != string::npos)
                nextRentalID = stoi(line.substr(line.find('=') + 1));
            continue;
        }
        istringstream ss(line);
        int rid, cid, vid, days, active;
        double cost;
        char delim;

        ss >> rid >> delim >> cid >> delim >> vid >> delim
           >> days >> delim >> cost >> delim >> active;

        Customer* c = findCustomer(cid);
        Vehicle*  v = findVehicle(vid);
        if (!c || !v) continue;

        Rental* r = new Rental(rid, c, v, days);
        if (!active) r->closeRental();
        rentals.push_back(r);
    }
}
