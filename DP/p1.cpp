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
    vi dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
            if (i >= j)
                dp[i] += dp[i - j];
        dp[i] %= mod;
    }
    cout << dp[n] <<endl ;
}