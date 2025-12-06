#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define pb(i) push_back(i)
#define all(x) (x).begin(), (x).end()

signed main()
{
    ll n, cnt = 0, ans = 0;
    cin >> n;
    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        events.push_back({x, 1});
        events.push_back({y, -1});
    }
    sort(all(events));
    for (auto [time, type] : events)
    {
        cnt += type;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}