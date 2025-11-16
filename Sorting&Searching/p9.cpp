#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector < ll > ;
#define pb(i) push_back(i)
#define all(x)(x).begin(), (x).end()

signed main()
{
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll pos1 = -1 ;
        for(int i = 0 ; i< n ; i++){
            if(s[i]=='1') pos1 = i ;
        }
        ll ans = 0;
        for(int i = 0 ; i< pos1 ; i++){
            if(s[i]=='0') ans++;
        }
        cout<<ans<<endl;
    }
}