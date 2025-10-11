#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

signed main()
{
    ll n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        sum += x;
    }
    cout << n * (n + 1) / 2 - sum;
    return 0;
}