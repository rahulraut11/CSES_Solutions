// Knight grid
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9 + 7;

signed main()
{
    ll n;
    cin >> n;
    vector<vi> dist(n, vi(n, 1e9));
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;
    pair<int, int> move[8] = {{1, -2}, {-1, -2}, {2, -1}, {-2, -1}, {2, 1}, {-2, 1}, {-1, 2}, {1, 2}};

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (auto [dx, dy] : move)
        {
            int newx = r + dx, newy = c + dy;
            if (max(newx, newy) < n && min(newx, newy) >= 0 && dist[newx][newy] == 1e9)
            {
                q.push({newx, newy});
                dist[newx][newy] = dist[r][c] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}