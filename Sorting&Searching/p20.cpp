// Nested Ranges Check
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
#define pb(i) push_back(i)
#define all(x) (x).begin(), (x).end()

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<tuple<int, int, int>> ranges;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        ranges.push_back({x, y, i});
    }
    sort(ranges.begin(), ranges.end(), [](const auto &a, const auto &b)
         {
             if (get<0>(a) != get<0>(b))
                 return get<0>(a) < get<0>(b); 
             return get<1>(a) > get<1>(b); });
    
    vi contained(n, 0), containing(n, 0);
    int maxm = INT_MIN, minm = INT_MAX;
    for (auto [l, r, i] : ranges)
    {
        if (maxm >= r && (maxm != INT_MIN))
            contained[i] = 1;
        maxm = max(maxm, r);
    }
    tuple<int, int, int> x;
    for (int i = n - 1; i >= 0; i--)
    {
        x = ranges[i];
        if (minm <= get<1>(x) && (minm != INT_MAX))
            containing[get<2>(x)] = 1;
        minm = min(minm, get<1>(x));
    }
    for (int i : containing)
        cout << i << " ";
    cout << endl;
    for (int i : contained)
        cout << i << " ";
    cout << endl;
}