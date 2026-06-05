#ifndef RENTAL_H
#define RENTAL_H

#include "Customer.h"
#include "Vehicle.h"

// ============================================================
//  Class — Rental  (R3, R4, R5)
//  Represents a single rental transaction.
//  Records are never deleted — they are "closed" on return.
// ============================================================
class Rental {
private:
    int       rentalID;
    Customer* customer;
    Vehicle*  vehicle;
    int       days;
    double    totalCost;
    bool      active;

public:
    Rental(int id, Customer* cust, Vehicle* veh, int d);

    int       getID()       const;
    Customer* getCustomer() const;
    Vehicle*  getVehicle()  const;
    int       getDays()     const;
    double    getCost()     const;
    bool      isActive()    const;

    void closeRental();
    void displayInfo() const;
};

#endif
