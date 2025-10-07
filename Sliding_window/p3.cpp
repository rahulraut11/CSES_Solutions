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
    ll res = 0;
    for (int i = 0; i < k; i++)
    {
        res ^= v[i];
    }
    int sum = res;
    for (int i = k; i < n; i++)
    {
        sum = sum ^ v[i - k] ^ v[i];
        res ^= sum;
    }
    cout << res << endl;
    return 0;
}