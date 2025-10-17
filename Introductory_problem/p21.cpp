// grid coloring
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9 + 7;

signed main()
{
    ll n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i + j) % 2)
            {
                if (grid[i][j] == 'A')
                    grid[i][j] = 'C';
                else
                    grid[i][j] = 'A';
            }
            else
            {
                if (grid[i][j] == 'B')
                    grid[i][j] = 'D';
                else
                    grid[i][j] = 'B';
            }
            cout << grid[i][j];
            // set<char> s;
            // if (i != 0)
            //     s.insert(grid[i - 1][j]);
            // if (j != 0)
            //     s.insert(grid[i][j - 1]);
            // s.insert(grid[i][j]);
            // for (char c = 'A'; c <= 'D'; c++)
            // {
            //     if (!s.count(c))
            //     {
            //         grid[i][j] = c;
            //         cout << c;
            //         break;
            //     }
            // }
        }
        cout << endl;
    }
}