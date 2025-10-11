#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

signed main()
{
    string s;
    cin >> s;
    ll n = s.size();
    ll ans = 0, cur = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            cur++;
        else
            cur = 0;
        ans = max(ans, cur);
    }
    cout << ans + 1;
    return 0;
}