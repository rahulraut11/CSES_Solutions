// gray code
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9 + 7;

vector<string> f(int i)
{
    if (i == 1)
    {
        vector<string> ans;
        ans.push_back("0");
        ans.push_back("1");
        return ans;
    }
    vector<string> prev = f(i - 1);
    vector<string> rev = prev;
    reverse(rev.begin(), rev.end());
    for (auto &s : prev)
        s = "0" + s;
    for (auto &s : rev)
    {
        s = "1" + s;
        prev.push_back(s);
    }
    return prev;
}

signed main()
{
    int n;
    cin >> n;
    vector<string> ans = f(n);
    for (string s : ans)
        cout << s << endl;
}