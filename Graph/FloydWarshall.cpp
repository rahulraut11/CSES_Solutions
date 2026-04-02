#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;
#define pb(i) push_back(i)
#define all(x) (x).begin(), (x).end()

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

    vector<vi> dist(n + 1, vi(n + 1, 1e18));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                dist[i][j] = 0;
            else if (adjmatrix[i][j] != LLONG_MAX)
                dist[i][j] = adjmatrix[i][j];

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    while (q--)
    {
        int from, to;
        cin >> from >> to;
        if (dist[from][to] == 1e18)
            cout << "-1" << '\n';
        else
            cout << dist[from][to] << '\n';
    }
}