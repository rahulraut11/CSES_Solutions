#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

signed main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 5; i <= n; i *= 5)
    {
        ans += n / i;
    }
    cout << ans << endl;
}