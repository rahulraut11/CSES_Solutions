#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

signed main()
{
    int n;
    cin >> n;
    vi a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] < a[i]){
            ans += a[i] - a[i + 1];
            a[i+1] = a[i];}
    }
    cout << ans;

    return 0;
}