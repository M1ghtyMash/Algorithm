#include <bits/stdc++.h>
using namespace std;

class EditDistance
{
private:
    string S, T;
    int m, n, counter;
    vector<vector<int>> Etable;

public:
    EditDistance(string p, string q)
    {
        S = p;
        T = q;
        m = S.length();
        n = T.length();
        counter = 0;
        Etable.assign(m + 1, vector<int>(n + 1, -1));
    }

    int recursiveEditDistance(int x, int y)
    {
        counter++;

        if (Etable[x][y] >= 0)
            return Etable[x][y];

        if (x == 0)
            return y;
        if (y == 0)
            return x;

        if (S[x - 1] == T[y - 1])
        {
            int t0 = (Etable[x - 1][y - 1] >= 0) ? Etable[x - 1][y - 1] : recursiveEditDistance(x - 1, y - 1);
            Etable[x][y] = t0;
            return Etable[x][y];
        }

        int t1 = (Etable[x][y - 1] >= 0) ? Etable[x][y - 1] : recursiveEditDistance(x, y - 1);
        int t2 = (Etable[x - 1][y] >= 0) ? Etable[x - 1][y] : recursiveEditDistance(x - 1, y);
        int t3 = (Etable[x - 1][y - 1] >= 0) ? Etable[x - 1][y - 1] : recursiveEditDistance(x - 1, y - 1);

        Etable[x][y] = 1 + min({t1, t2, t3});
        return Etable[x][y];
    }

    void calculateED()
    {
        int total = recursiveEditDistance(m, n);
        cout << "Total edit distance: " << total << endl;
        cout << "Recursive calls: " << counter << endl;
    }
};

int main()
{
    string p, q;
    cout << "Enter 2 strings: ";
    getline(cin, p);
    getline(cin, q);

    EditDistance e(p, q);
    e.calculateED();

    return 0;
}
