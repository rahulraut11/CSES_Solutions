#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

signed main()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll tiles = i * i;
        ll totalways = tiles * (tiles - 1) / 2;
        ll badways = 0;
        badways += (i - 4) * (i - 4) * 8;
        badways += (i - 4) * 4 * 6;
        badways += (i - 3) * 4 * 4;
        badways += 8 * 3;
        badways += 4 * 2;
        badways /= 2;
        cout << totalways - badways << endl;
    }
}