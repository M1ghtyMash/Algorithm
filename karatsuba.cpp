#include <bits/stdc++.h>
using namespace std;

class Multiply
{
public:
    int counter = 0;
kjhhkjkjhgfdfgdfgddsasdaewqwqeqwertrtyrty
    long long karatsubaMul(long long x, long long y, int n)
    {
        counter++;
        int m;

        if (n == 1)
            return x * y;

        if (n % 2 == 0)
            m = n / 2;
        else
            m = (n + 1) / 2;

        long long a, b, c, d, e, h, k, result;
        long long powerM = pow(10, m);

        a = x / powerM;
        b = x % powerM;
        c = y / powerM;
        d = y % powerM;

        e = karatsubaMul(a, c, m);
        k = karatsubaMul(c - d, a - b, m);
        h = karatsubaMul(b, d, m);

        result = e * pow(10, 2 * m) + (e + h - k) * pow(10, m) + h;
        return result;
    }
};

int main()
{
    long long x, y;
    int n1, n2, n;
    long long result;

    cout << "Enter 1st number: ";
    cin >> x;
    cout << "Enter 2nd number: ";
    cin >> y; 

    n1 = (int)log10(x) + 1;
    n2 = (int)log10(y) + 1;
    n = min(n1, n2);

    Multiply m;
    result = m.karatsubaMul(x, y, n);

    cout << "Multiplication value = " << result << endl;
    cout << "Number of recursive calls = " << m.counter << endl;

    return 0;
}
