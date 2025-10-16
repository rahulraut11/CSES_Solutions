// apple division
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9 + 7;

int mindiff(int index, int target, int n, vi &p)
{
    if (target == 0)
        return 0;
    if (index >= n)
        return target;
    int take = 1e8, nottake = 1e8;
    nottake = mindiff(index + 1, target, n, p);
    take = mindiff(index + 1, target - p[index], n, p);
    return abs(min(take, nottake));
}

int main()
{
    int n;
    cin >> n;
    vi p(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        sum += p[i];
    }
    int ans = mindiff(0, sum / 2, n, p);

    ans = ans * 2;
    if (sum % 2)
        ans++;
    cout << ans << endl;
    return 0;
}