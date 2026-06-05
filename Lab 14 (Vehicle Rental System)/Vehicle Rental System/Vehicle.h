#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
using namespace std;

// ============================================================
//  Abstract Base Class "Vehicle"
//  Encapsulates common attributes for all vehicle types.
// ============================================================
class Vehicle {
protected:
    int    vehicleID;
    string makeModel;
    double dailyRate;
    bool   available;

public:
    Vehicle(int id, const string& model, double rate);
    virtual ~Vehicle();

    // ---------- Getters ----------
    int    getID()        const;
    string getMakeModel() const;
    double getDailyRate() const;
    bool   isAvailable()  const;

    // ---------- Setters ----------
    void setAvailable(bool status);

    // ---------- Pure Virtual Methods (Abstraction) ----------
    virtual string getType()               const = 0;
    virtual double calculateCost(int days) const = 0;
    virtual void   displayInfo()           const = 0;
    virtual string getExtraAttribute()     const = 0;
};

#endif
