#include <iostream>
using namespace std;

/* ================= ABSTRACT CLASS ================= */
class HospitalStaff {
protected:
    string name;

public:
    // Pure virtual function
    virtual void performDuty() = 0;
};

/* ================= DOCTOR CLASS ================= */
class Doctor : public HospitalStaff {
public:
    Doctor(string n) {
        name = n;
    }

    void performDuty() override {
        cout << name << " (Doctor) is diagnosing patients." << endl;
    }
};

/* ================= NURSE CLASS ================= */
class Nurse : public HospitalStaff {
public:
    Nurse(string n) {
        name = n;
    }

    void performDuty() override {
        cout << name << " (Nurse) is assisting patients." << endl;
    }
};

/* ================= RECEPTIONIST CLASS ================= */
class Receptionist : public HospitalStaff {
public:
    Receptionist(string n) {
        name = n;
    }

    void performDuty() override {
        cout << name << " (Receptionist) is managing appointments." << endl;
    }
};

/* ================= MAIN FUNCTION ================= */
int main() {
    Doctor d("Dr. Ali");
    Nurse n("Sara");
    Receptionist r("Ahmed");

    d.performDuty();
    n.performDuty();
    r.performDuty();

    return 0;
}
