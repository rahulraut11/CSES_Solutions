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

    unordered_map<int, int> freq;
    set<int> s;

    for (int i = 0; i <= k; i++)
    {
        s.insert(i);
    }
    for (int i = 0; i < k; i++)
    {
        int x = a[i];
        if (x <= k)
        {
            if (freq[x] == 0)
                s.erase(x);
            freq[x]++;
        }
    }
    cout << *s.begin() << " ";

    for (int i = k; i < n; i++)
    {
        int next = a[i], old = a[i - k];
        // remove old
        if (old <= k)
        {
            freq[old]--;
            if (freq[old] == 0)
                s.insert(old);
        }
        // insert next
        if (next <= k)
        {
            if (freq[next] == 0)
                s.erase(next);
            freq[next]++;
        }
        cout << *s.begin() << " ";
    }
    return 0;
}