#include <bits/stdc++.h>
using namespace std;

int counter = 0;
vector<int> f; // memoization array

int fibo(int n)
{
    if (n < 0)
        return -1;

    counter++;

    if (f[n] != -1)
    { // already calculated
        cout << f[n] << " ";
        return f[n];
    }

    if (n == 0)
    {
        f[n] = 0;
        cout << f[n] << " ";
        return f[n];
    }

    if (n == 1)
    {
        fibo(0); // calculate fibo(0) first
        f[n] = 1;
        cout << f[n] << " ";
        return f[n];
    }

    int i1, i2;
    if (f[n - 1] != -1)
        i1 = f[n - 1];
    else
        i1 = fibo(n - 1);

    if (f[n - 2] != -1)
        i2 = f[n - 2];
    else
        i2 = fibo(n - 2);

    f[n] = i1 + i2; // store value
    cout << f[n] << " ";
    return f[n];
}

int main()
{
    int n;
    cout << "Upto what element? (last index) ";
    cin >> n;

    if (n < 0)
        return 0;

    f.assign(n + 1, -1); // initialize memo table

    cout << "Total data: " << n + 1 << endl;
    cout << "The Fibonacci series is: ";
    fibo(n);
    cout << "\nTotal calls: " << counter << endl;

    return 0;
}
