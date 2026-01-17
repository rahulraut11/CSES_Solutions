#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb(i) push_back(i)
#define all(x) (x).begin(), (x).end()

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll mod = 1e9 + 7;

    int n, x;
    cin >> n >> x;
    vi pages(n), price(n);
    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];
    vi dp(x + 1);
    for (int i = 0; i < n; i++)
        for (int j = x; j >= 0; j--)
            if (price[i] <= j)
                dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);

    cout << dp[x] << endl;
}