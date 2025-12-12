// Mission Coin Sum
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
#define pb(i) push_back(i)
#define all(x) (x).begin(), (x).end()

signed main()
{
    ll n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));
    ll val = 1;
    for (ll i : a)
    {
        if (val < i)
            break;
        else
            val += i;
    }
    cout << val << endl;
}