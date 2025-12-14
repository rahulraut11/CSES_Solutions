// Josephus Problem I
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
#define pb(i) push_back(i)
#define all(x) (x).begin(), (x).end()

void solve(vi a)
{
    if (a.size() == 1)
    {
        cout << a[0] << endl;
        return;
    }
    int n = a.size();
    for (int i = 1; i < n; i += 2)
        cout << a[i] << endl;
    vi na;
    if (n % 2 == 0)
    {
        for (int i = 0; i < n; i += 2)
            na.pb(a[i]);
    }
    else
    {
        na.pb(a[n - 1]);
        for (int i = 0; i < n - 1; i += 2)
            na.pb(a[i]);
    }
    solve(na);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    solve(a);
}