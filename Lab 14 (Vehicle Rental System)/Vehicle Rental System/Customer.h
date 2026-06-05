#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
using namespace std;

// ============================================================
//  Class — Customer  (R2)
//  Encapsulates customer identity and rental state.
// ============================================================
class Customer {
private:
    int    customerID;
    string name;
    bool   hasActiveRental;

public:
    Customer(int id, const string& n);

    int    getID()    const;
    string getName()  const;
    bool   isRenting() const;

    void setRenting(bool status);
    void displayInfo() const;
};

#endif
