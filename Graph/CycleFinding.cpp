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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        edges.push_back({from, to, cost});
    }

    vi dist(n + 1, 0);
    vi par(n + 1, -1);
    int final = -1;

    for (int i = 1; i <= n; i++)
    {
        final = -1;
        for (auto e : edges)
        {
            int from = e[0], to = e[1], cost = e[2];
            if (dist[to] > dist[from] + cost)
            {
                par[to] = from;
                dist[to] = dist[from] + cost;
                if (i == n)
                    final = to;
            }
        }
    }

    if (final == -1)
        cout << "NO" << "\n";
    else
    {
        for (int i = 1; i <= n; i++)
            final = par[final];

        cout << "YES" << "\n";

        vector<int> cycle;
        int curr = final;
        do
        {
            cycle.push_back(curr);
            curr = par[curr];
        } while (curr != final);

        cycle.push_back(final);

        reverse(cycle.begin(), cycle.end());

        for (int v : cycle)
            cout << v << " ";
    }
    return 0;
}