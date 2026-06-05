#include "Vehicle.h"

Vehicle::Vehicle(int id, const string& model, double rate)
{
    vehicleID = id;
    makeModel = model;
    dailyRate = rate;
    available = true;
}

Vehicle::~Vehicle() {}

int    Vehicle::getID()        const { return vehicleID; }
string Vehicle::getMakeModel() const { return makeModel; }
double Vehicle::getDailyRate() const { return dailyRate; }
bool   Vehicle::isAvailable()  const { return available; }

void Vehicle::setAvailable(bool status) { available = status; }
