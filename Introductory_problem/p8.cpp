#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

signed main()
{
    ll n;
    cin >> n;
    if (n % 4 == 1 || n % 4 == 2)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        
            vi a, b;
            ll x = 0, y = 0;
            for (int i = n; i > 0; i--)
            {
                if (x > y)
                {
                    b.push_back(i);
                    y += i;
                }
                else
                {
                    a.push_back(i);
                    x += i;
                }
            }
            cout << a.size() << endl;
            for (auto i : a)
                cout << i << " ";
            cout << endl
                 << b.size() << endl;
            for (auto i : b)
                cout << i << " ";
        
    }
}