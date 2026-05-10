#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;

public:
    // Constructor to initialize values
    Distance(int f, int i) {
        feet = f;
        inches = i;
    }

    // Overload == operator (member function)
    bool operator==(Distance d) {
        return (feet == d.feet && inches == d.inches);
    }
};

int main() {
    Distance d1(5, 10);
    Distance d2(5, 10);

    if (d1 == d2)
        cout << "Distances are equal" << endl;
    else
        cout << "Distances are not equal" << endl;

    return 0;
}
