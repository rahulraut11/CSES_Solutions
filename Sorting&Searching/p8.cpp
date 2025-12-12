// Maximum Subarray Sum
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
    ll ans = a[0], end = a[0];
    for (ll i = 1; i < n; i++)
    {
        end = max(a[i], end + a[i]);
        ans = max(ans, end);
    }
    cout << ans << endl;
}