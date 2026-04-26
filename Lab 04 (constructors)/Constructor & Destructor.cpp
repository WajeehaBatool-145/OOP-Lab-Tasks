#include <iostream>
using namespace std;

class Locker
{
public:
    // Constructor
    Locker()
    {
        cout << "Locker allocated to customer." << endl;
    }

    // Destructor
    ~Locker()
    {
        cout << "Locker returned by customer." << endl;
    }
};

int main()
{

    {
        Locker l1;
    } // Destructor automatically called here

    cout << "Block ended\n" << endl;

    //  Dynamic object using new
    Locker* l2 = new Locker();

    // Manually deleting object
    delete l2;

    return 0;
}
