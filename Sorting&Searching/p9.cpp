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
    vi p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    sort(all(p));
    ll med = p[n / 2], ans = 0;
    for (int i : p)
        ans += abs(med - i);
    cout << ans << endl;
}