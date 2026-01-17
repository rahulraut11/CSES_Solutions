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
    int n;
    cin >> n;
    vi dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int t = i;
        while (t > 0)
        {
            dp[i] = min(dp[i], 1 + dp[i - (t % 10)]);
            t /= 10;
        }
    }
    cout << dp[n] << endl;
}