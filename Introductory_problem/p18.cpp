//raab game
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9 + 7;

signed main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        if (a + b > n)
        {
            cout << "NO" << endl;
            continue;
        }
        ll draws = n - a - b;
        n -= draws;
        if (n > 0 && (a >= n || b >= n))
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        for (int i = 1; i <= n + draws; i++)
        {
            cout << i << ' ';
        }
        cout << endl;
        for (int i = 1; i <= n; i++)
        {
            int x = i + a;
            if (x > n)
                x -= n;
            cout << x << " ";
        }
        for (int i = n + 1; i <= n + draws; i++)
            cout << i << ' ';
        cout << endl;
    }
}