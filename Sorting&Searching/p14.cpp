// Towers
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
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        auto it = s.upper_bound(x);
        if (it != s.end())
            s.erase(it);
        s.insert(x);
    }
    cout << s.size() << endl;
}