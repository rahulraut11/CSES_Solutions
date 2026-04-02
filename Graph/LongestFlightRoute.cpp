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

    int n, m;
    cin >> n >> m;
    vector<vi> adj(n + 1);
    vi indeg(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        indeg[y]++;
    }
    // given that there are no cycles
    // use topo sort ? then do dfs travel from 1 to n
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0)
            q.push(i);
    vi dp(n + 1, -1e18);
    vi par(n + 1, -1);
    dp[1] = 1;
    vi topo;
    vi vis(n + 1);
    vis[1] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.pb(node);
        for (auto adjnode : adj[node])
        {
            indeg[adjnode]--;
            if (indeg[adjnode] == 0)
                q.push(adjnode);
            if (dp[node] != -1e18 && dp[adjnode] < dp[node] + 1)
            {
                par[adjnode] = node;
                dp[adjnode] = dp[node] + 1;
            }
        }
    }
    if (dp[n] == -1e18)
    {
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }
    vi ans;
    for (int i = n; i != 1; i = par[i])
        ans.pb(i);
    ans.pb(1);
    reverse(all(ans));
    cout << (int)ans.size() << "\n";
    for (int i : ans)
        cout << i << " ";
}