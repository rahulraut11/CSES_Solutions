#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;

#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>

signed main()
{

    ordered_set s;
    map<ll, ll> freq;
    ll n, k;
    cin >> n >> k;
    vi a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll ans = 0;

    for (ll i = 0; i < k; i++)
    {
        ll x = a[i];
        s.insert(x);
        ll y = s.order_of_key(x);
        freq[x]++;
        ans += s.size() - y - freq[x];
    }
    cout << ans << " ";
    for (ll i = k; i < n; i++)
    {
        // remove old
        ll old = a[i - k], next = a[i];
        ans -= s.order_of_key(old);
        freq[old]--;
        s.erase(s.upper_bound(old));

        // insert next
        s.insert(next);
        ll y = s.order_of_key(next);
        freq[next]++;
        ans += k - y - freq[next];

        cout << ans << " ";
    }
    return 0;
}
