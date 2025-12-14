// Traffic Lights
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
    ll x, n;
    cin >> x >> n;
    set<ll> pos;
    pos.insert(0);
    pos.insert(x);
    multiset<ll> length;
    length.insert(x);
    for (ll i = 0; i < n; i++)
    {
        ll p;
        cin >> p;
        auto upr = pos.upper_bound(p);
        auto lwr = upr;
        lwr--;
        ll r = *upr, l = *lwr;
        length.erase(length.find(r - l));
        length.insert(r - p);
        length.insert(p - l);
        pos.insert(p);
        cout << *length.rbegin() << " ";
    }
}