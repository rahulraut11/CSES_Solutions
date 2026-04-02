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

    int n, m;
    cin >> n >> m;
    vector<vi> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
    }
    vi parent(n + 1, -1);
    vi vis(n + 1);
    vi path(n + 1);
    int start = -1, end = -1;

    function<bool(int)> dfs = [&](int node)
    {
        vis[node] = path[node] = 1;
        for (auto adjnode : adj[node])
        {
            if (!vis[adjnode])
            {
                parent[adjnode] = node;
                if (dfs(adjnode))
                    return true;
            }
            else if (path[adjnode])
            {
                start = adjnode;
                end = node;
                return true;
            }
        }
        path[node] = 0;
        return false;
    };

    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            if (dfs(i))
                break;
        }
    if (start == -1)
    {
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }
    vi ans;
    ans.pb(start);
    for (int i = end; i != start; i = parent[i])
    {
        ans.pb(i);
    }
    ans.pb(start);
    reverse(all(ans));
    cout << ans.size() << "\n";
    for (int i : ans)
        cout << i << " ";
}