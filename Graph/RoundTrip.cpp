#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb(i) push_back(i)
#define all(x) (x).begin(), (x).end()

int st = -1, ed = -1;

bool dfs(int node, int par, vi &vis, vi &parent, vector<vi> &adj)
{
    vis[node] = 1;
    for (auto adjnode : adj[node])
    {
        if (adjnode == par)
            continue;
        if (!vis[adjnode])
        {
            parent[adjnode] = node;
            if (dfs(adjnode, node, vis, parent, adj))
                return true;
        }
        else
        {
            st = adjnode;
            ed = node;
            return true;
        }
    }
    return false;
}

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
        adj[y].pb(x);
    }
    vi parent(n + 1, -1), vis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            if (dfs(i, -1, vis, parent, adj))
                break;
    }
    if (st == -1)
    {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    vi path;
    path.pb(st);
    int curr = ed;
    while (curr != st)
    {
        path.pb(curr);
        curr = parent[curr];
    }
    path.pb(st);
    reverse(all(path));
    cout << path.size() << '\n';
    for (int i : path)
        cout << i << " ";
    return 0;
}