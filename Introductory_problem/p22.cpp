// digit queries
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9 + 7;

signed main()
{
    int q;
    cin >> q;
    while (q--)
    {
        ll k;
        cin >> k;
        ll cnt = 9;
        ll skipped = 0;
        for (int len = 1; true; len++)
        {
            if (cnt * len < k)
            {
                k -= len * cnt;
                skipped += cnt;
            }
            else
            {
                ll skip = (k - 1) / len;
                skipped += skip;
                k -= skip * len;
                ll ans = skipped + 1;
                cout << to_string(ans)[k - 1] << endl;
                break;
            }
            cnt *= 10;
        }
    }
}