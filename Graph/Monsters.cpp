#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    vector<vector<int>> distM(n, vector<int>(m, 1e9)), distA(n, vector<int>(m, 1e9)), parent(n, vector<int>(m, -1));
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    char dir[4] = {'U', 'D', 'L', 'R'};

    distM.assign(n, vector<int>(m, 1e9));
    distA.assign(n, vector<int>(m, 1e9));
    parent.assign(n, vector<int>(m, -1));

    queue<pair<int, int>> qM, qA;
    int sx, sy, ex = -1, ey = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 'M')
            {
                qM.push({i, j});
                distM[i][j] = 0;
            }
            if (g[i][j] == 'A')
            {
                qA.push({i, j});
                distA[i][j] = 0;
                sx = i;
                sy = j;
            }
        }
    }
    while (!qM.empty())
    {
        auto [x, y] = qM.front();
        qM.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] != '#' && distM[nx][ny] == 1e9)
            {
                distM[nx][ny] = distM[x][y] + 1;
                qM.push({nx, ny});
            }
        }
    }
    while (!qA.empty())
    {
        auto [x, y] = qA.front();
        qA.pop();
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
        {
            ex = x;
            ey = y;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] != '#' && distA[nx][ny] == 1e9)
            {
                if (distA[x][y] + 1 < distM[nx][ny])
                {
                    distA[nx][ny] = distA[x][y] + 1;
                    parent[nx][ny] = i;
                    qA.push({nx, ny});
                }
            }
        }
    }
    if (ex == -1)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n"
             << distA[ex][ey] << "\n";
        string path = "";
        while (ex != sx || ey != sy)
        {
            int p = parent[ex][ey];
            path += dir[p];
            ex -= dx[p];
            ey -= dy[p];
        }
        reverse(path.begin(), path.end());
        cout << path << "\n";
    }
    return 0;
}