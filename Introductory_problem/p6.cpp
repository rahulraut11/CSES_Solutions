#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

signed main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> y>> x;
        ll maxm = max(x, y);
        ll dist, ans;
        if (maxm % 2==0)
        {
            dist = abs(maxm - y) + abs(1 - x);
        }
        else
        {
            dist = abs(maxm - x) + abs(1 - y);
        }
        ans = maxm * maxm - dist;
        cout << ans << endl;
    }
    return 0;
}