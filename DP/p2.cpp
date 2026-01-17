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

    int n, x;
    cin >> n >> x;
    vi c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    vi dp(x + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
            if (c[j] <= i)
                dp[i] = min(dp[i - c[j]], dp[i]);
        dp[i]++;
    }
    if (dp[x] == 1e9 + 1)
        cout << -1 << endl;
    else
        cout << dp[x] << endl;
}