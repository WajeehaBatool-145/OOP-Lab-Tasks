# 🚗 Vehicle Rental System

A console-based **Vehicle Rental Management System** developed in **C++** using Object-Oriented Programming principles. The system allows management of vehicles, customers, rentals, returns, and persistent file storage.

---

## 📌 Project Overview

This application simulates a vehicle rental company that manages a fleet of:

* Cars
* Motorbikes
* Trucks

Customers can rent available vehicles for a specified number of days. Rental records are preserved even after vehicles are returned, providing complete rental history.

---

## ✨ Features

### Fleet Management

* Add Cars, Motorbikes, and Trucks
* View complete fleet information
* Remove available vehicles from the fleet
* Track vehicle availability

### Customer Management

* Register customers with unique IDs
* View registered customers
* Restrict customers to one active rental at a time

### Rental Processing

* Rent available vehicles
* Prevent double-booking of vehicles
* Automatically mark rented vehicles as unavailable

### Vehicle Return

* Return rented vehicles
* Mark vehicles available again
* Preserve rental history by closing records instead of deleting them

### Cost Calculation

* Standard daily rate for Cars
* 20% surcharge for Trucks
* 10% discount for Motorbikes rented longer than 7 days

### Data Persistence

* Automatic saving of:

  * Vehicles
  * Customers
  * Rentals
* Automatic loading on program startup

---

## 🧠 OOP Concepts Demonstrated

### Encapsulation

Private data members with controlled access through public member functions.

### Abstraction

`Vehicle` is implemented as an abstract base class containing pure virtual functions.

### Inheritance

Derived vehicle types inherit common functionality from the base `Vehicle` class.

```text
Vehicle
├── Car
├── Motorbike
└── Truck
```

### Polymorphism

Vehicles are stored using `Vehicle*` pointers, enabling runtime function binding.

```cpp
totalCost = vehicle->calculateCost(days);
```

### Dynamic Memory Management

Objects are created dynamically and cleaned up using destructors to prevent memory leaks.

### File Handling

Persistent storage implemented through text files.

---

## 🏗️ Class Hierarchy

```text
Vehicle (Abstract Base Class)
│
├── Car
│   └── numSeats
│
├── Motorbike
│   └── engineCC
│
└── Truck
    └── payloadTonnes

Customer

Rental
│
├── Customer*
└── Vehicle*

RentalSystem
│
├── Fleet Management
├── Customer Management
├── Rental Processing
└── File Handling
```

---

## 💰 Pricing Rules

| Vehicle Type        | Pricing Rule             |
| ------------------- | ------------------------ |
| Car                 | Daily Rate × Days        |
| Truck               | Daily Rate × Days × 1.20 |
| Motorbike (>7 Days) | Daily Rate × Days × 0.90 |

---

## ✅ Requirements Coverage

| Requirement           | Status |
| --------------------- | ------ |
| Manage Fleet          | ✅      |
| Register Customers    | ✅      |
| Process Rentals       | ✅      |
| Calculate Rental Cost | ✅      |
| Return Vehicles       | ✅      |
| Print Summary Reports | ✅      |
| File Persistence      | ✅      |

---

## 👨‍💻 Developed For

**Object-Oriented Programming with C++**

Vehicle Rental System Lab Project

