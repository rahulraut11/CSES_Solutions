#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n);
        int maxm = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > maxm)
                maxm = a[i];
        }
        map<int, int> divs;
        for (int i : a)
        {
            for (int x = 1; x * x <= i; x++)
            {
                if (i % x == 0)
                {
                    divs[x]++;
                    if (x * x != i)
                        divs[i / x]++;
                }
            }
        }
        for (int i = maxm - 1; i >= 2; i--)
        {
            int mult = 0;
            if (divs.count(i) == 1)
            {
                mult = divs[i];
            }
            if (n - mult - 2 >= 0)
            {
                cout << i << endl;
                break;
            }
        }
    }
}