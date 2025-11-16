#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define pb(i) push_back(i)
#define all(x) (x).begin(), (x).end()

signed main()
{
    ll n, m;
    cin >> n >> m;
    vi cost(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    vi maxm(m);
    for (int i = 0; i < m; i++)
        cin >> maxm[i];
    sort(cost.begin(), cost.end(), greater<int>());
    ll i = 0, j = 0;
    while (i <= n || j <= m)
    {
        if (maxm[j] >= cost[i])
        {
            cout << cost[i] << endl;
            j++;
            i++;
        }
        else
            i++;
    }
}