// Playlist
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
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    map<int, int> pos;
    int ans = 0, last = 0;
    for (int i = 1; i <= n; i++)
    {
        last = max(last, pos[a[i]]);
        ans = max(ans, i - last);
        pos[a[i]] = i;
    }
    cout << ans << endl;
}