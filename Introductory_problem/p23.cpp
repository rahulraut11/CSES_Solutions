// String Reorder
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9 + 7;

signed main()
{
    string s;
    cin >> s;
    int n = s.size();
    string ans;
    vi freq(26);
    for (char c : s)
        freq[c - 'A']++;
    while (ans.size() < n)
    {
        bool found = false;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0 && (ans.empty() || ans.back() != ('A' + i)))
            {
                freq[i]--;
                ans += ('A' + i);
                int suf = n - ans.size();

                bool possible = true;
                for (int j = 0; j < 26; j++)
                {
                    if (i != j)
                    {
                        if (freq[j] > (suf + 1) / 2)
                        {
                            possible = false;
                            break;
                        }
                    }
                    else
                    {
                        if (freq[j] > suf / 2)
                        {
                            possible = false;
                            break;
                        }
                    }
                }
                if (possible)
                {
                    found = true;
                    break;
                }
                else
                {
                    freq[i]++;
                    ans.pop_back();
                }
            }
        }
        if (!found)
            break;
    }
    if (ans.size())
        cout << ans << endl;
    else
        cout << -1 << endl;
}