#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

int main()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    unordered_map<int, int> mp;
    for (int i = 0; i < k; i++)
    {
        mp[a[i]]++;
    }

    vi res(n - k + 1, 0);
    res[0] = mp.size();

    for (int i = k; i < n; i++)
    {
        mp[a[i - k]]--;
        if (mp[a[i - k]] == 0)
            mp.erase(a[i - k]);
        mp[a[i]]++;
        res[i - k + 1] = mp.size();
    }
    for (int i = 0; i <= n - k; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}