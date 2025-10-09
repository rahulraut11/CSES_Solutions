// incomplete 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int area(vi &histo)
{
    int n = histo.size();
    stack<int> st;
    int maxm = 0;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i]))
        {
            int height = histo[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxm = max(maxm, width * height);
        }
        st.push(i);
    }
    return maxm;
}
int main()
{
    ll n;
    cin >> n;
    vi a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << area(a);
}