#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

int main()
{
    int n, k;
    cin >> n >> k;

    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    vi v(n);
    v[0] = x;

    for (int i = 1; i < n; i++)
        v[i] = (1LL * a * v[i - 1] + b) % c;

    deque<pair<ll, int>> dq; // value , index

    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && dq.back().first >= x)
        {
            dq.pop_back();
        }
        dq.push_back({x, i});
        x = (a * x + b) % c;
    }
    ll result = dq.front().first;
    for (int i = k; i < n; i++)
    {
        while (!dq.empty() && dq.back().first >= x)
        {
            dq.pop_back();
        }
        dq.push_back({x, i});

        while (!dq.empty() && dq.front().second <= i - k)
            dq.pop_front();

        result ^= dq.front().first;
        x = (a * x + b) % c;
    }
    cout << result << endl;

    return 0;
}