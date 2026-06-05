#include "VehicleTypes.h"
#include <iostream>
#include <iomanip>

// ============================================================
//  Car — method definitions
// ============================================================

string Car::getType() const {
    return "Car";
}

int Car::getSeats() const {
    return numSeats;
}

// R4: No surcharge / discount for Car
double Car::calculateCost(int days) const {
    return dailyRate * days;
}

string Car::getExtraAttribute() const {
    return "Seats: " + to_string(numSeats);
}

void Car::displayInfo() const {
    cout << fixed << setprecision(2);
    cout << "  [CAR  ] ID:" << vehicleID
         << " | " << makeModel
         << " | Rs." << dailyRate << "/day"
         << " | Seats: " << numSeats
         << " | " << (available ? "AVAILABLE" : "RENTED")
         << "\n";
}

// ============================================================
//  Motorbike — method definitions
// ============================================================

string Motorbike::getType() const {
    return "Motorbike";
}

int Motorbike::getEngineCC() const {
    return engineCC;
}

// R4: 10% discount if rental > 7 days
double Motorbike::calculateCost(int days) const {
    double cost = dailyRate * days;
    if (days > 7)
        cost *= 0.90;   // 10% discount
    return cost;
}

string Motorbike::getExtraAttribute() const {
    return "Engine: " + to_string(engineCC) + "cc";
}

void Motorbike::displayInfo() const {
    cout << fixed << setprecision(2);
    cout << "  [MOTO ] ID:" << vehicleID
         << " | " << makeModel
         << " | Rs." << dailyRate << "/day"
         << " | Engine: " << engineCC << "cc"
         << " | " << (available ? "AVAILABLE" : "RENTED")
         << "\n";
}

// ============================================================
//  Truck — method definitions
// ============================================================

string Truck::getType() const {
    return "Truck";
}

double Truck::getPayload() const {
    return payloadTonnes;
}

// R4: 20% surcharge for Trucks
double Truck::calculateCost(int days) const {
    return dailyRate * days * 1.20;   // 20% surcharge
}

string Truck::getExtraAttribute() const {
    return "Payload: " + to_string((int)payloadTonnes) + " tonnes";
}

void Truck::displayInfo() const {
    cout << fixed << setprecision(2);
    cout << "  [TRUCK] ID:" << vehicleID
         << " | " << makeModel
         << " | Rs." << dailyRate << "/day"
         << " | Payload: " << payloadTonnes << "t"
         << " | " << (available ? "AVAILABLE" : "RENTED")
         << "\n";
}
