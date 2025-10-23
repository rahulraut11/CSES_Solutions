#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define pb(i) push_back(i)
#define all(x) (x).begin(), (x).end()

signed main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < m && b[j] < a[i] - k)
            j++;
        if (j == m)
            break;
        if (abs(a[i] - b[j]) <= k)
        {
            ans++;
            j++;
        }
    }
    cout << ans << endl;
}