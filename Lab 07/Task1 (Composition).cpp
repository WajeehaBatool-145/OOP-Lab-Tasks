#include <iostream>
using namespace std;

// Display class (used inside Calculator)
class Display {
private:
    double lastResult;

public:
    Display() {
        lastResult = 0;
    }

    void showResult(double result) {
        lastResult = result;
        cout << "Result: " << lastResult << endl;
    }

    double getLastResult() {
        return lastResult;
    }
};

// Calculator class (uses composition)
class Calculator {
private:
    Display display;   // Composition: Calculator HAS-A Display

public:
    void add(double a, double b) {
        double result = a + b;
        display.showResult(result);
    }

    void multiply(double a, double b) {
        double result = a * b;
        display.showResult(result);
    }

    void showLastResult() {
        cout << "Last displayed result: " << display.getLastResult() << endl;
    }
};

// Main function
int main() {
    Calculator calc;

    calc.add(5, 3);        // 8
    calc.multiply(4, 2);    // 8

    calc.showLastResult();  // last stored result

    return 0;
}
