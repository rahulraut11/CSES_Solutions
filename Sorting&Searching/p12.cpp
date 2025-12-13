// Collecting Numbers II
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
    vi a(n + 1), pos(n + 2);
    pos[0] = 0, pos[n + 1] = n + 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    ll cnt = 1;
    for (int i = 1; i < n; i++)
        if (pos[i] > pos[i + 1])
            cnt++;
    while (m--)
    {
        int i, j;
        cin >> i >> j;
        if (i > j)
            swap(i, j);
        ll x = a[i], y = a[j];
        if (x == y - 1)
            cnt++;
        if (x == y + 1)
            cnt--;

        if (pos[x - 1] > i && pos[x - 1] < j)
            cnt--;
        if (pos[x + 1] > i && pos[x + 1] < j)
            cnt++;
        if (pos[y - 1] > i && pos[y - 1] < j)
            cnt++;
        if (pos[y + 1] > i && pos[y + 1] < j)
            cnt--;
        pos[x] = j, pos[y] = i;
        swap(a[i], a[j]);
        cout << cnt << endl;
    }
}