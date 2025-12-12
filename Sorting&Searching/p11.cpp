// Collecting  Numbers
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
    vi pos(n + 1), a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    ll ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (pos[i] > pos[i + 1])
            ans++;
    }
    cout << ans << endl;
}