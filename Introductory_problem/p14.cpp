#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9 + 7;

void f(int n, int from, int to)
{
    if (n == 0)
        return;
    int other = 6 - from - to;
    f(n - 1, from, other);
    cout << from << " " << to << endl;
    f(n - 1, other, to);
}

int main()
{
    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl; // 2^n - 1
    f(n, 1, 3);
}