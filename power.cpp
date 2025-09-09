#include <bits/stdc++.h>
using namespace std;

class Recursive {
public:
    long long powerefficient(int b, int n) {
        if (n == 0) return 1LL;
        if (n == 1) return b;

        long long temp = powerefficient(b, n / 2);

        if (n % 2 == 0)
            return temp * temp;
        else
            return b * temp * temp;
    }
};

int main() {
    int b, n;
    cout << "Enter base and power: ";
    cin >> b >> n;

    Recursive a;
    long long result = a.powerefficient(b, n);

    cout << "The output is " << result << endl;

    return 0;
}
