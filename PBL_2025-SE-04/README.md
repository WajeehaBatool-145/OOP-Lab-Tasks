# ✈️ Airline Management System
## A console-based C++ OOP project that simulates a complete airline management system — supporting flight scheduling, passenger registration, ticket booking, cancellation, and persistent state via file I/O.

### 📚 Course: Object-Oriented Programming (OOP)
### 🎓 Session: 2025-29
### 💻 Language: C++


## 📋 Table of Contents

#### Features
#### Project Structure
#### Class Hierarchy
#### Menu Options
#### OOP Concepts Used
#### File Format


## ✨ Features

✅ Add, remove, list, and search flights (Domestic / International / Charter)

✅ Register, list, and remove passengers (Economy / Business / First Class)

✅ Book and cancel tickets with automatic fare calculation

✅ View per-passenger booking history

✅ Occupancy report per flight

✅ Revenue report across all flights

✅ Persistent state — auto-saves on exit, auto-loads on startup via state.txt

✅ Custom exception handling for full flights and invalid cancellations


## 📁 Project Structure
AirlineManagementSystem/
│
├── main.cpp            # Entry point, menu loop

├── Airline.h/.cpp      # Core controller class

├── Flight.h/.cpp       # Abstract Flight + 3 subclasses

├── Passenger.h/.cpp    # Abstract Passenger + 3 subclasses

├── Ticket.h/.cpp       # Ticket data class

├── Exception.h/.cpp    # Custom exception classes

└── state.txt           # Auto-generated save file (or use sample_data.txt)

## 🏗️ Class Hierarchy
Flight  (abstract)

├── DomesticFlight       baseFare = PKR 5,000

├── InternationalFlight  baseFare = PKR 20,000

└── CharterFlight        baseFare = PKR 30,000

Passenger  (abstract)

├── EconomyPassenger

├── BusinessPassenger

└── FirstClassPassenger

Airline   ──── has many ──→  Flight*, Passenger*, Ticket*

## ========== AIRLINE MANAGEMENT SYSTEM ==========
  1.  Add Flight
  2.  List Flights
  3.  Search Flight
  4.  Remove Flight
  5.  Register Passenger
  6.  List Passengers
  7.  Remove Passenger
  8.  Book Ticket
  9.  Cancel Ticket
  10. Passenger Booking Details
  11. Occupancy Report
  12. Revenue Report
  13. Save System State
  0.  Exit
  
================================================
## 🧠 OOP Concepts Used
### 🔷 Abstraction
Flight and Passenger are abstract classes with pure virtual functions, defining a common interface for all derived classes.

### 🔷 Inheritance
DomesticFlight, InternationalFlight, and CharterFlight inherit from Flight.
Similarly, different passenger types inherit from the Passenger base class.

### 🔷 Polymorphism
Achieved using vector<Flight*> and vector<Passenger*>.
Runtime polymorphism is used through virtual functions like type(), baseFare(), and show().

### 🔷 Encapsulation
Data members are kept private or protected.
Access is controlled through public getter and setter functions.

### 🔷 Exception Handling
Custom exceptions are implemented:
FlightFullException
InvalidCancellationException

### 🔷 Operator Overloading
operator<< is overloaded for displaying Flight objects.
operator== is used for comparing Ticket objects.

### 🔷 File I/O
Data persistence is handled using:
ifstream
ofstream
Functions like saveState() and loadState() manage system state.

### 🔷 STL Usage
std::vector is used for dynamic storage of:
Flights
Passengers
Tickets

## 👩‍💻 Author
### Wajeeha Batool
### Object-Oriented Programming Project

