#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define pb(i) push_back(i)
#define all(x) (x).begin(), (x).end()

signed main()
{
    int n, x;
    cin >> n >> x;
    vi p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    sort(p.begin(), p.end());
    ll i = 0, j = n - 1, ans = 0;
    while (i <= j)
    {
        if (p[i] + p[j] <= x)
        {
            ans++;
            i++;
            j--;
        }
        else
        {
            ans++;
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}