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
    ll n, k, x;
    cin >> n >> k >> x;
    vi a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));

    vi pre(n + 1);
    for (ll i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i - 1];
    ll ans = -1;
    for (ll i = n - k + 1; i <= n; i++)
    {
        if (pre[i - n + k] >= x)
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}