# ✈️ Airline Management System
## OOP Project — 2025-SE-04
### A console-based Airline Management System built in C++ using Object-Oriented Programming concepts including inheritance, polymorphism, operator overloading, and file handling.

## 📁 Project Structure
### ├── main.cpp          — Entry point, main menu loop
### ├── Flight.h/.cpp     — Flight base class + Domestic, International, Charter
### ├── Passenger.h/.cpp  — Passenger base class + Economy, Business, FirstClass
### ├── Ticket.h/.cpp     — Ticket class with operator overloading
### ├── Airline.h/.cpp    — Core system: manages all operations
### ├── Exception.h/.cpp  — Custom exception classes
### └── sample_data.txt   — Pre-loaded test data (flights, passengers, tickets)

## 🏗️ Class Hierarchy
## Flight  (abstract)
### ├── DomesticFlight       → Base Fare: Rs. 5,000
### ├── InternationalFlight  → Base Fare: Rs. 20,000
### └── CharterFlight        → Base Fare: Rs. 30,000

## Passenger  (abstract)
### ├── EconomyPassenger
### ├── BusinessPassenger
### └── FirstClassPassenger

## ⚙️ Object-Oriented Programming Concepts Used

### 🔹 Inheritance

The system uses inheritance to create specialized flight and passenger types.

* `Flight` → `DomesticFlight`, `InternationalFlight`, `CharterFlight`
* `Passenger` → `EconomyPassenger`, `BusinessPassenger`, `FirstClassPassenger`

This reduces code duplication and promotes reusability.

### 🔹 Polymorphism

Runtime polymorphism is achieved through virtual functions.

The functions `type()`, `baseFare()`, and `show()` are declared as virtual in the base classes and overridden in derived classes, allowing different object types to be handled through a common interface.

### 🔹 Abstraction

`Flight` and `Passenger` are designed as abstract classes containing pure virtual functions.

This enforces a common structure while allowing each derived class to provide its own implementation.

### 🔹 Encapsulation

Data members are protected from direct access by keeping them private or protected and exposing only the necessary public member functions.

This improves security and maintainability of the code.

### 🔹 Operator Overloading

Custom operators are implemented to improve usability:

* `operator<<` for displaying Flight and Ticket information.
* `operator==` for comparing Ticket objects.

### 🔹 Exception Handling

The system uses custom exception classes to handle runtime errors gracefully.

Examples include:

* `FlightFullException`
* `InvalidCancellationException`

These exceptions prevent unexpected program crashes and provide meaningful error messages.

### 🔹 File Handling (Persistence)

Program data can be saved and restored using:

* `saveState()`
* `loadState()`

This allows flight and booking information to persist between program executions.

### 🔹 Dynamic Memory Management

Objects are created dynamically using `new` and stored in vectors of pointers.

Allocated memory is properly released using `delete` to prevent memory leaks and ensure efficient resource management.

---

## ✅ Features Demonstrated

* Inheritance
* Polymorphism
* Abstraction
* Encapsulation
* Operator Overloading
* Exception Handling
* File Handling
* Dynamic Memory Management
* STL Vector Usage
* Runtime Binding

## ⚠️ Error Handling

The Airline Management System includes robust error handling mechanisms to ensure reliable and user-friendly operation.

### 🔹 Flight Full Exception

When a passenger attempts to book a seat on a flight that has no available seats, a `FlightFullException` is thrown.

**System Response:**

* Booking request is rejected.
* An appropriate error message is displayed to the user.

### 🔹 Invalid Ticket Cancellation

If a user attempts to cancel a ticket that does not exist in the system, an `InvalidCancellationException` is triggered.

**System Response:**

* Cancellation request is denied.
* A clear error message is shown.

### 🔹 Duplicate Passenger ID

Each passenger must have a unique ID.

**System Response:**

* Registration of the duplicate passenger is prevented.
* An error message notifies the user about the duplicate ID.

### 🔹 Flight Not Found

If a booking, search, or cancellation operation references a flight that does not exist in the system:

**System Response:**

* The requested operation is aborted.
* An informative error message is displayed.

### ✅ Benefits of Error Handling

* Prevents invalid operations.
* Protects data integrity.
* Improves system reliability.
* Provides meaningful feedback to users.
* Reduces the chances of program crashes.
## Author
### Wajeeha Batool

