// Josephus Problem II
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define pb(i) push_back(i)
#define all(x) (x).begin(), (x).end()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
#define len(x) int((x).size())

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    ordered_set nums;
    for (int i = 1; i <= n; i++)
        nums.insert(i);

    int pos = 0;
    while (!nums.empty())
    {
        pos = (pos + k) % len(nums);
        auto it = nums.find_by_order(pos);
        cout << *it << " ";
        nums.erase(it);
    }
}