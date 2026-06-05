
#include "RentalSystem.h"
#include <limits>
#include <fstream>

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void showMenu() {
    cout << "\n";
    cout << "==========================================\n";
    cout << "       VEHICLE RENTAL SYSTEM  MENU        \n";
	cout << "==========================================\n";
    cout << "FLEET \n";
    cout << "1. Add Car \n";
    cout << "2. Add Motorbike \n";
    cout << "3. Add Truck \n";
    cout << "4. Display Fleet \n";
    
    cout << "==========================================\n";
    cout << "CUSTOMERS \n";
    cout << "5. Register Customer \n";
    cout << "6. Display Customers \n";
    cout << "==========================================\n";
    cout << "RENTALS \n";
    cout << "7. Rent a Vehicle \n";
    cout << "8. Return a Vehicle \n";
    cout << "==========================================\n";
    cout << "REPORTS \n";
    cout << "9. Print Summary \n";
    cout << "==========================================\n";
    cout << "10. Remove Vehicle from Fleet \n";
    cout << "0. Exit \n";
    cout << "==========================================\n";
    cout << "  Choice: ";
}

void loadSampleData(RentalSystem& sys) {
    cout << "\n  [INFO] First run detected — loading sample data...\n";
    // Cars
    sys.addCar("Toyota Corolla",  3500.0, 5);
    sys.addCar("Honda Civic",     4000.0, 5);
    sys.addCar("Suzuki Alto",     2500.0, 4);
    // Motorbikes
    sys.addMotorbike("Yamaha YBR-125", 800.0,  125);
    sys.addMotorbike("Honda CB-150R", 1200.0,  150);
    // Trucks
    sys.addTruck("Hino 300 Series", 7000.0, 3.5);
    sys.addTruck("Isuzu NLR",       6000.0, 2.0);
    // Customers
    sys.registerCustomer("Ali Raza");
    sys.registerCustomer("Sara Khan");
    sys.registerCustomer("Usman Tariq");
    cout << "  [INFO] Sample data loaded.\n";
}

int main() {
   

    RentalSystem sys;

    // Seed sample data on very first run (no vehicles file yet)
    {
        ifstream check("vehicles.txt");
        if (!check.good()) loadSampleData(sys);
        check.close();
    }

    int choice;
    while (true) {
        showMenu();

        if (!(cin >> choice)) {
            clearInput();
            cout << "  [ERROR] Invalid input. Enter a number 0-9.\n";
            continue;
        }

        switch (choice) {

        case 1: {
            string model; double rate; int seats;
            cout << "  Make/Model : "; clearInput(); getline(cin, model);
            cout << "  Daily Rate : "; cin >> rate;
            cout << "  Seats      : "; cin >> seats;
            sys.addCar(model, rate, seats);
            break;
        }
        case 2: {
            string model; double rate; int cc;
            cout << "  Make/Model : "; clearInput(); getline(cin, model);
            cout << "  Daily Rate : "; cin >> rate;
            cout << "  Engine CC  : "; cin >> cc;
            sys.addMotorbike(model, rate, cc);
            break;
        }
        case 3: {
            string model; double rate; double payload;
            cout << "  Make/Model    : "; clearInput(); getline(cin, model);
            cout << "  Daily Rate    : "; cin >> rate;
            cout << "  Payload (ton) : "; cin >> payload;
            sys.addTruck(model, rate, payload);
            break;
        }
        case 4:
            sys.displayFleet();
            break;

        case 5: {
            string name;
            cout << "  Customer Name : "; clearInput(); getline(cin, name);
            sys.registerCustomer(name);
            break;
        }
        case 6:
            sys.displayCustomers();
            break;

        case 7: {
            int cid, vid, days;
            sys.displayFleet();
            sys.displayCustomers();
            cout << "  Customer ID : "; cin >> cid;
            cout << "  Vehicle ID  : "; cin >> vid;
            cout << "  Days        : "; cin >> days;
            sys.rentVehicle(cid, vid, days);
            break;
        }
        case 8: {
            int rid;
            cout << "  Rental ID to return : "; cin >> rid;
            sys.returnVehicle(rid);
            break;
        }
        case 9:
            sys.printSummary();
            break;

        case 10: {
            int vid;
            sys.displayFleet();
            cout << "  Vehicle ID (remove karne ke liye): "; cin >> vid;
            sys.removeVehicle(vid);
            break;
        }

        case 0:
            cout << "\n  Data saved. Goodbye!\n";
            return 0;

        default:
            cout << "  [ERROR] Invalid choice. Enter 0-9.\n";
        }
    }
}
