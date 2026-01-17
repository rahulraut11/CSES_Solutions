#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
#define pb(i) push_back(i)
#define all(x) (x).begin(), (x).end()

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll mod = 1e9 + 7;

    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    vector<vi> dp(n, vi(n));
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == '.')
            dp[i][0] = 1;
        else
            break;
    }
    for (int i = 0; i < n; i++)
    {
        if (grid[0][i] == '.')
            dp[0][i] = 1;
        else
            break;
    }
    for (int i = 1; i < n; i++) 
    {
        for (int j = 1; j < n; j++)
        {
            if (grid[i][j] == '.')
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    cout << dp[n - 1][n - 1] << endl;
}