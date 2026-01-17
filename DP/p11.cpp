#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;

using pii = pair<int, int>;

#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int pref = 0, ans = 0;
    ordered_set st;
    st.insert({0, 0});

    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == 'A')
            pref++;
        else if (s[i - 1] == 'B')
            pref--;
        ans += st.order_of_key({pref, -1});
        st.insert({pref, i});
    }
    cout << ans << endl;
}
