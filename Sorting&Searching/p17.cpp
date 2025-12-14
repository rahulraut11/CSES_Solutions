// Distinct Value Subsequences
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
    const int MOD = 1e9 + 7;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    unordered_map<int, int> freq;
    for (int i : a)
        freq[i]++;
    ll ans = 1;
    for (auto [num, cnt] : freq)
    {
        ans *= (cnt + 1);
        ans = ans % MOD;
    }
    cout << ans - 1 << endl;
}