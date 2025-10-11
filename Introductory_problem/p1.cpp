#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

int main()
{
    ll n;
    cin >> n;
    while (n != 1)
    {
        cout << n << ' ';
        if (n % 2)
            n = 3 * n + 1;
        else
            n /= 2;
    }
    cout << 1;
    return 0;
}