#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
multiset<int> small, large;
void eq()
{
    if (small.size() > large.size() + 1)
    {
        large.insert(*small.rbegin());
        small.erase(--small.end());
    }
    if (large.size() > small.size())
    {
        small.insert(*large.begin());
        large.erase(large.begin());
    }
    if (!small.empty() && !large.empty() && (*large.begin() < *small.rbegin()))
    {
        large.insert(*small.rbegin());
        small.insert(*large.begin());
        small.erase(--small.end());
        large.erase(large.begin());
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < k; i++)
    {
        small.insert(a[i]);
        eq();
    }
    cout << *small.rbegin() << " ";

    for (int i = k; i < n; i++)
    {
        int old = a[i - k], next = a[i];
        // erase the old
        if (small.find(old) != small.end())
            small.erase(small.find(old));
        else
            large.erase(large.find(old));
        // insert next 
        small.insert(next);
        eq();
        cout << *small.rbegin() << " ";
    }
    return 0;
}