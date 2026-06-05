#ifndef RENTAL_SYSTEM_H
#define RENTAL_SYSTEM_H

#include "VehicleTypes.h"
#include "Customer.h"
#include "Rental.h"
#include <vector>
#include <string>
using namespace std;

// ============================================================
//  Class — RentalSystem
//  Manages fleet, customers, and rental operations.
//  Uses file handling to persist data between runs.
// ============================================================
class RentalSystem {
private:
    vector<Vehicle*>  fleet;
    vector<Customer*> customers;
    vector<Rental*>   rentals;

    int nextVehicleID;
    int nextCustomerID;
    int nextRentalID;

    const string VEHICLES_FILE;
    const string CUSTOMERS_FILE;
    const string RENTALS_FILE;

    // Internal lookup helpers
    Vehicle*  findVehicle (int id) const;
    Customer* findCustomer(int id) const;
    Rental*   findRental  (int id) const;

    // File I/O helpers
    void saveVehicles()  const;
    void saveCustomers() const;
    void saveRentals()   const;
    void loadVehicles();
    void loadCustomers();
    void loadRentals();

public:
    RentalSystem();
    ~RentalSystem();

    // R1 — Fleet management
    void addCar      (const string& model, double rate, int seats);
    void addMotorbike(const string& model, double rate, int cc);
    void addTruck    (const string& model, double rate, double payload);
    void removeVehicle(int vehicleID);
    void displayFleet() const;

    // R2 — Customer registration
    void registerCustomer(const string& name);
    void displayCustomers() const;

    // R3 — Rent a vehicle
    void rentVehicle(int customerID, int vehicleID, int days);

    // R5 — Return a vehicle
    void returnVehicle(int rentalID);

    // R6 — Summary report
    void printSummary() const;

    // Persist all data to files
    void saveAll() const;
    void loadAll();
};

#endif
