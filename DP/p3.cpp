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

    int n, x, mod = 1e9 + 7;
    cin >> n >> x;
    vi c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    vi dp(x + 1);
    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
            if (c[j] <= i)
                dp[i] += dp[i - c[j]];
        dp[i] %= mod ;
    }
    cout << dp[x] << endl;
}