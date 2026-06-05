#include "Rental.h"
#include <iostream>
#include <iomanip>

Rental::Rental(int id, Customer* cust, Vehicle* veh, int d)
    : rentalID(id), customer(cust), vehicle(veh), days(d), active(true)
{
    totalCost = veh->calculateCost(d);   // Polymorphic cost (R4)
}

int       Rental::getID()       const { return rentalID; }
Customer* Rental::getCustomer() const { return customer; }
Vehicle*  Rental::getVehicle()  const { return vehicle; }
int       Rental::getDays()     const { return days; }
double    Rental::getCost()     const { return totalCost; }
bool      Rental::isActive()    const { return active; }

void Rental::closeRental() { active = false; }

void Rental::displayInfo() const {
    cout << fixed << setprecision(2);
    cout << "  Rental #" << rentalID
         << " | Customer: " << customer->getName()
         << " (ID " << customer->getID() << ")"
         << " | Vehicle: " << vehicle->getMakeModel()
         << " (" << vehicle->getType() << ")"
         << " | Days: " << days
         << " | Cost: Rs." << totalCost
         << " | Status: " << (active ? "ACTIVE" : "RETURNED")
         << "\n";
}
