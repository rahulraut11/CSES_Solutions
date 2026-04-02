#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;
#define pb(i) push_back(i)
#define all(x) (x).begin(), (x).end()

vi dikstra(ll node, vector<vector<pii>> &adj)
{
    ll n = adj.size();
    vi dist(n + 1, LLONG_MAX);
    dist[node] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, node});
    while (!pq.empty())
    {
        auto [currdist, curr] = pq.top();
        pq.pop();
        if (currdist > dist[curr])
            continue;
        for (auto [adjnode, cost] : adj[curr])
        {
            if (dist[adjnode] > dist[curr] + cost)
            {
                dist[adjnode] = dist[curr] + cost;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }
    return dist;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<pii>> adj(n + 1);
    vector<vi> adjmatrix(n + 1, vi(n + 1, LLONG_MAX));
    for (ll i = 0; i < m; i++)
    {
        ll from, to, cost;
        cin >> from >> to >> cost;
        adjmatrix[from][to] = min(adjmatrix[from][to], cost);
        adjmatrix[to][from] = min(adjmatrix[to][from], cost);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (adjmatrix[i][j] != LLONG_MAX)
                adj[i].push_back({j, adjmatrix[i][j]});

    vector<vi> dist;
    vi buffer(n + 1, 0);
    dist.pb(buffer);
    for (ll i = 1; i <= n; i++)
    {
        vi curr = dikstra(i, adj);
        dist.pb(curr);
    }
    while (q--)
    {
        ll from, to;
        cin >> from >> to;
        if (dist[from][to] == LLONG_MAX)
            cout << -1 << '\n';
        else
            cout << dist[from][to] << '\n';
    }
}