#ifndef VEHICLE_TYPES_H
#define VEHICLE_TYPES_H

#include "Vehicle.h"

// ============================================================
//  Derived Class — Car
//  Extra attribute: number of seats
// ============================================================
class Car : public Vehicle {
private:
    int numSeats;

public:
    // Constructor — initializer list se Vehicle ka constructor call hota hai
    Car(int id, const string& model, double rate, int seats)
        : Vehicle(id, model, rate), numSeats(seats) {}

    string getType()               const override;
    int    getSeats()              const;
    double calculateCost(int days) const override;
    string getExtraAttribute()     const override;
    void   displayInfo()           const override;
};

// ============================================================
//  Derived Class — Motorbike
//  Extra attribute: engine CC
// ============================================================
class Motorbike : public Vehicle {
private:
    int engineCC;

public:
    // .h mein sirf naam — koi :: nahi
    Motorbike(int id, const string& model, double rate, int cc)
        : Vehicle(id, model, rate), engineCC(cc) {}

    string getType()               const override;
    int    getEngineCC()           const;
    double calculateCost(int days) const override;
    string getExtraAttribute()     const override;
    void   displayInfo()           const override;
};

// ============================================================
//  Derived Class — Truck
//  Extra attribute: payload capacity in tonnes
// ============================================================
class Truck : public Vehicle {
private:
    double payloadTonnes;

public:
    // Same pattern — initializer list, koi :: nahi
    Truck(int id, const string& model, double rate, double payload)
        : Vehicle(id, model, rate), payloadTonnes(payload) {}

    string getType()               const override;
    double getPayload()            const;
    double calculateCost(int days) const override;
    string getExtraAttribute()     const override;
    void   displayInfo()           const override;
};

#endif
