#include <bits/stdc++.h>
using namespace std;

class LCS
{
public:
    string A, B;
    int m, n;
    int lcslength;
    vector<vector<int>> L;
    string lcsString;

    LCS(string p, string q)
    {
        A = p;
        B = q;
        m = A.size();
        n = B.size();
        L.assign(m + 1, vector<int>(n + 1, 0));
        lcslength = 0;
    }

    int dynamicLCS()
    {
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                    L[i][j] = 0;
                else if (A[i - 1] == B[j - 1])
                    L[i][j] = L[i - 1][j - 1] + 1;
                else
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }

        lcslength = L[m][n];
        return lcslength;
    }

    void printLCS()
    {
        int i = m, j = n;
        int k = lcslength;
        lcsString = string(k, ' '); // initialize string of length k

        while (i > 0 && j > 0)
        {
            if (A[i - 1] == B[j - 1])
            {
                k--;
                lcsString[k] = A[i - 1];
                i--;
                j--;
            }
            else if (L[i - 1][j] > L[i][j - 1])
                i--;
            else
                j--;
        }

        cout << "\nLCS length = " << lcslength << endl;
        cout << "The LCS string is: " << lcsString << endl;
    }
};

int main()
{
    string p, q;
    cout << "Enter 1st string: ";
    cin >> p;
    cout << "Enter 2nd string: ";
    cin >> q;

    LCS a(p, q);
    a.dynamicLCS();
    a.printLCS();

    return 0;
}
