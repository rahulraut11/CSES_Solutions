//creating strings
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9 + 7;
map<char, int> freq;
int n;
vector<string> ans;

void build(string s)
{
    if ((int)s.size() == n)
    {
        ans.push_back(s);
        return;
    }
    for (auto [c, cnt] : freq)
    {

        freq[c]--;
        if (freq[c] >= 0)
            build(s + c);
        freq[c]++;
    }
}

signed main()
{
    string s;
    cin >> s;
    n = s.size();
    for (char c : s)
        freq[c]++;
    build("");
    cout << ans.size() << endl;
    for (string i : ans)
        cout << i << endl;
}

// int cnt = 0;
// sort(s.begin(), s.end());
// vector<string> ans;
// do
// {
//     cnt++;
//     ans.push_back(s);
// } while (next_permutation(s.begin(), s.end()));
// cout << cnt << endl;
// for (string s : ans)
//     cout << s << endl;