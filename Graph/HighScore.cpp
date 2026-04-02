#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
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
}