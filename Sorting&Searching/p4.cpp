// concert tickets
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define pb(i) push_back(i)
#define all(x) (x).begin(), (x).end()

signed main()
{
    ll n, m, x;
    cin >> n >> m;
    multiset<int> price;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        price.insert(x);
    }
    vi maxm(m);
    for (int i = 0; i < m; i++)
        cin >> maxm[i];
    for (int i = 0; i < m; i++)
    {
        auto it = price.upper_bound(maxm[i]);
        if (it == price.begin())
            cout << -1 << endl;
        else
        {
            it--;
            cout << *it << endl;
            price.erase(it);
        }
    }
}
