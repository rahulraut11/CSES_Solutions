#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define pb(i) push_back(i)
#define all(x) (x).begin(), (x).end()

signed main()
{
    ll n, x;
    cin >> n >> x;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> hash;
    for (int i = 0; i < n; i++)
    {
        int cmp = x - a[i];
        if (hash.count(cmp))
        {
            cout << hash[cmp] + 1 << " " << i + 1 << "\n";
            return 0;
        }
        hash[a[i]] = i;
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}