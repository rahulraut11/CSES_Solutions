// Ferris wheel
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
    sort(all(p));
    int l = 0, r = n - 1, ans = 0;
    while (l <= r)
    {
        if (l == r)
        {
            ans++;
            break;
        }
        if (p[l] + p[r] <= x)
        {
            ans++;
            l++;
            r--;
        }
        else
        {
            r--;
            ans++;
        }
    }
    cout << ans << endl;
}