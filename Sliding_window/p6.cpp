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

    unordered_map<int, int> freq; // value , freq
    set<pair<int, int>> s;        // -freq , value

    // first make window of size k
    for (int i = 0; i < k; i++)
    {
        int x = a[i];
        if (freq[x] > 0)
            s.erase({-freq[x], x});
        freq[x]++;
        s.insert({-freq[x], x});
    }

    cout << s.begin()->second << " ";

    for (int i = k; i < n; i++)
    {
        int next = a[i], old = a[i - k];
        // remove old from set
        s.erase({-freq[old], old});
        freq[old]--;
        if (freq[old] > 0)
            s.insert({-freq[old], old});
        // insert next in set

        if (freq[next] > 0)
            s.erase({-freq[next], next});
        freq[next]++;
        s.insert({-freq[next], next});

        cout << s.begin()->second << " ";
    }
    return 0;
}