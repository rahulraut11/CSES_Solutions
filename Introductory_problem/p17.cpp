// Queen chessboard
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int ans = 0;
vector<bool> upward(8); // col in which i can place Q will be false
vector<bool> diag1(15);
vector<bool> diag2(15);
void place(int row, vector<string> &grid)
{
    // base case
    if (row == 8)
    {
        ans++;
        return;
    }
    for (int col = 0; col < 8; col++)
    {
        if (grid[row][col] == '.' && !upward[col] && !diag1[row - col + 7] && !diag2[row + col])
        {
            // block is safe to place a queen
            grid[row][col] = 'Q';
            upward[col] = true;
            diag1[row - col + 7] = true;
            diag2[row + col] = true;

            place(row + 1, grid);

            diag2[row + col] = false;
            diag1[row - col + 7] = false;
            upward[col] = false;
            grid[row][col] = '.';
        }
    }
}

int main()
{
    vector<string> grid(8);
    // 8x8matrix
    for (int i = 0; i < 8; i++)
        cin >> grid[i];

    place(0, grid);

    cout << ans << endl;
    return 0;
}