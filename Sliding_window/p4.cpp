#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

int main()
{
    int n, k;
    cin >> n >> k;
    vi v(n);
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    v[0] = x;
    for (int i = 1; i < n; i++)
    {
        v[i] = (1LL * a * v[i - 1] + b) % c;
    }
    vi pref(n, 0);
    vi suf(n + 1, 0);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % k == 0)
            pref[i] = v[i];
        else
            pref[i] = (pref[i - 1] | v[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (i % k == k - 1)
            suf[i] = v[i];
        else
            suf[i] = (suf[i + 1] | v[i]);
    }

    for (int i = 0; i <= n - k; i++)
    {
        int l = i, r = i + k - 1;
        int cur_or = (pref[r] | suf[l]);
        res ^= cur_or;
    }
    cout << res << endl;
    return 0;
}