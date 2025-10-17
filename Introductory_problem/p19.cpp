// mex grid
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9 + 7;

signed main()
{
    int n;
    cin >> n;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            // set<int> s;
            // for (int i = 0; i < r; i++)
            // {
            //     s.insert(grid[i][c]);
            // }
            // for (int j = 0; j < c; j++)
            //     s.insert(grid[r][j]);
            // int x = 0;
            // while (s.count(x))
            // {
            //     x++;
            // }

            cout << (r ^ c) << " " ;
        }
        cout << endl;
    }
}