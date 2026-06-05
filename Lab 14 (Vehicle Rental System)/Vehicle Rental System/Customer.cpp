#include "Customer.h"

Customer::Customer(int id, const string& n)
    : customerID(id), name(n), hasActiveRental(false) {}

int    Customer::getID()     const { return customerID; }
string Customer::getName()   const { return name; }
bool   Customer::isRenting() const { return hasActiveRental; }

void Customer::setRenting(bool status) { hasActiveRental = status; }

void Customer::displayInfo() const {
    cout << "  Customer #" << customerID
         << " " << name
         << (hasActiveRental ? "  [Has active rental]" : "  [Free]")
         << "\n";
}
