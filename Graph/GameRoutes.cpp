#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb(i) push_back(i)
#define all(x) (x).begin(), (x).end()

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int mod = 1e9 + 7;
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
    }
    vi dp(n + 1, -1);
    function<int(int)> dfs = [&](int node)
    {
        if (node == n)
            return 1;
        if (dp[node] != -1)
            return dp[node];
        ll cnt = 0;
        for (auto adjnode : adj[node])
        {
            cnt += dfs(adjnode);
            cnt %= mod;
        }
        return dp[node] = cnt;
    };
    int ans = dfs(1);
    cout << ans << "\n";
}