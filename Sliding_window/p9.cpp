#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
multiset<ll> small, large;
ll sumsmall = 0, sumlarge = 0;
void addNum(ll x)
{
    small.insert(x);
    sumsmall += x;

    if (!large.empty() && (*large.begin() < *small.rbegin()))
    {
        sumsmall -= *small.rbegin();
        sumlarge += *small.rbegin();
        large.insert(*small.rbegin());
        small.erase(--small.end());
    }
    if (small.size() > large.size() + 1)
    {
        sumsmall -= *small.rbegin();
        sumlarge += *small.rbegin();
        large.insert(*small.rbegin());
        small.erase(--small.end());
    }
    if (large.size() > small.size())
    {
        sumsmall += *large.begin();
        sumlarge -= *large.begin();
        small.insert(*large.begin());
        large.erase(large.begin());
    }
}

ll cost()
{
    ll med;
    if (large.size() > small.size())
        med = *large.begin();
    else
        med = *small.rbegin();
    ll ans;
    ans = med * small.size() - sumsmall + (sumlarge - med * large.size());
    return ans;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vi a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    for (ll i = 0; i < k; i++)
    {
        addNum(a[i]);
    }
    cout << cost() << " ";

    for (ll i = k; i < n; i++)
    {
        ll old = a[i - k], next = a[i];
        // first remove it
        if (small.find(old) != small.end())
        {
            small.erase(small.find(old));
            sumsmall -= old;
        }
        else
        {
            large.erase(large.find(old));
            sumlarge -= old;
        }
        // now insert next
        addNum(next);
        cout << cost() << " ";
    }
    cout << endl;
    return 0;
}