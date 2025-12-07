// Movie Festival
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
#define pb(i) push_back(i)
#define all(x) (x).begin(), (x).end()

signed main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> movie;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        movie.push_back({start, end});
    }
    sort(movie.begin(), movie.end(), [](const auto &a, const auto &b)
         { return a.second < b.second; });

    int ans = 1;
    int timer = movie[0].second;
    for (auto [a, b] : movie)
    {
        if (a >= timer)
        {
            ans++;
            timer = b;
        }
    }
    cout << ans << endl;
    return 0;
}