#include <iostream>
using namespace std;

// Recursive class
class Recursive
{
public:
    long long factorial(int x)
    {
        if (x <= 1)
            return 1LL;
        return x * factorial(x - 1);
    }
};

// Main program
int main()
{
    int x;
    cout << "Enter an integer number: ";
    cin >> x;

    Recursive a;
    long long result = a.factorial(x);

    cout << "The factorial value is " << result << endl;

    return 0;
}
