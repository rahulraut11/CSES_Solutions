#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

int main()
{

    int n, k;
    cin >> n >> k;
    ll sum = 0;
    vi v(n);
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    v[0] = x;
    for (int i = 1; i < n; i++)
    {
        v[i] = (1LL * a * v[i - 1] + b) % c;
    }
    ll init = 0;
    for (int i = 0; i < k; i++)
    {
        init += v[i];
    }
    ll ans = 0;
    ans ^= init;
    for (int i = k; i < n; i++)
    {
        init -= v[i - k];
        init += v[i];
        ans ^= init;
    }
    cout << ans << endl;

    return 0;
}