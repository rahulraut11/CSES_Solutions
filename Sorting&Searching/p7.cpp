// Sum of Two values
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
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        int cmp = x - a[i];
        if (hash.count(cmp))
        {
            found = true;
            cout << hash[cmp] + 1 << " " << i + 1 << endl;
            break;
        }
        hash[a[i]] = i;
    }
    if (!found)
        cout << "IMPOSSIBLE" << endl;
    return 0;
}