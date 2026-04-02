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
    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        adj[from].push_back({to, cost});
    }
    vector<vi> dist(n + 1, vi(2, 1e18));
    dist[1][0] = 0;
    priority_queue<pair<pii, int>, vector<pair<pii, int>>, greater<pair<pii, int>>> pq;
    pq.push({{0, 1}, 0});
    while (!pq.empty())
    {
        ll curr = pq.top().first.first, node = pq.top().first.second, state = pq.top().second;
        pq.pop();
        if (curr > dist[node][state])
            continue;
        for (auto [adjnode, cost] : adj[node])
        {
            if (state == 0)
            {
                if (dist[adjnode][0] > curr + cost)
                {
                    dist[adjnode][0] = curr + cost;
                    pq.push({{dist[adjnode][0], adjnode}, 0});
                }
                if (dist[adjnode][1] > curr + cost / 2)
                {
                    dist[adjnode][1] = curr + cost / 2;
                    pq.push({{dist[adjnode][1], adjnode}, 1});
                }
            }
            else
            {
                if (dist[adjnode][1] > curr + cost)
                {
                    dist[adjnode][1] = curr + cost;
                    pq.push({{dist[adjnode][1], adjnode}, 1});
                }
            }
        }
    }
    cout << dist[n][1] << "\n";
}