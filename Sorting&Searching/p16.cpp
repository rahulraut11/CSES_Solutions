// Distinct Values Subarrays
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
#define pb(i) push_back(i)
#define all(x) (x).begin(), (x).end()

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    map<int, int> freq;
    int l = 0;
    for (int r = 0; r < n; r++)
    {
        while (freq[a[r]] == 1)
        {
            freq[a[l]]--;
            if (freq[a[l]] == 0)
                freq.erase(a[l]);
            l++;
        }
        freq[a[r]]++;
        ans += r - l + 1;
    }
    cout << ans << endl;
}