// palindrome reorder
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

signed main()
{
    string s;
    cin >> s;
    map<char, int> freq;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        freq[s[i]]++;
    }
    int single = 0;
    for (auto [i, cnt] : freq)
    {
        if (cnt % 2)
            single++;
    }
    if (single > 1)
        cout << "NO SOLUTION" << endl;
    else
    {
        string ans;
        char sing = 'x';
        int fre = 0;
        for (auto [i, cnt] : freq)
        {
            if (cnt % 2 != 1)
                for (int j = 0; j < cnt / 2; j++)
                    ans.push_back(i);
            else
            {
                sing = i;
                fre = cnt;
            }
        }
        if (fre > 1)
        {
            for (int i = 0; i < (fre - 1) / 2; i++)
                ans.push_back(sing);
        }
        string rev = ans;
        reverse(rev.begin(), rev.end());
        if (sing != 'x')
            ans.push_back(sing);
        ans += rev;
        cout << ans;
    }
}
