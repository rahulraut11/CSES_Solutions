#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9 + 7;
int ans = 0, n = 7;
vector<vector<bool>> vis(n + 2, vector<bool>(n + 2, 0));
string s;

void dfs(int r, int c, int move)
{
    if (r == n && c == 1)
    {
        if (move == n * n - 1)
            ans++;
        return;
    }
    // diag check
    if (vis[r - 1][c - 1] && !vis[r - 1][c] && !vis[r][c - 1])
        return;
    if (vis[r - 1][c + 1] && !vis[r - 1][c] && !vis[r][c + 1])
        return;
    // trap check
    if (vis[r + 1][c] && vis[r - 1][c] && !vis[r][c + 1] && !vis[r][c - 1])
        return;
    if (!vis[r + 1][c] && !vis[r - 1][c] && vis[r][c + 1] && vis[r][c - 1])
        return;
    char cur = s[move];
    vis[r][c] = 1;
    if ((cur == '?' || cur == 'D') && !vis[r + 1][c])
        dfs(r + 1, c, move + 1);
    if ((cur == '?' || cur == 'U') && !vis[r - 1][c])
        dfs(r - 1, c, move + 1);
    if ((cur == '?' || cur == 'R') && !vis[r][c + 1])
        dfs(r, c + 1, move + 1);
    if ((cur == '?' || cur == 'L') && !vis[r][c - 1])
        dfs(r, c - 1, move + 1);
    vis[r][c] = 0;
}
signed main()
{
    cin >> s;
    for (int i = 0; i <= n + 1; i++)
    {
        vis[0][i] = 1;
        vis[i][0] = 1;
        vis[n + 1][i] = 1;
        vis[i][n + 1] = 1;
    }
    dfs(1, 1, 0);
    cout << ans << endl;
}