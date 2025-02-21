#include <bits/stdc++.h>
using namespace std;

#define ll long long
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tc; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n; cin >> n;

        vector<vector<ll>> arr(n, vector<ll>(n));
        for(auto &v: arr) {
            for(auto &x: v) {
                cin >> x;
            }
        }

        multiset<ll> st;
        for(ll i =0; i < n; i++) {
            ll c = 0;
            for(ll j = n-1; j >= 0; j--) {
                if(arr[i][j] != 1) break;
                else c++;
            }
            st.insert(c);
        }

        ll ans = 0;
        for(auto it = st.begin(); it != st.end(); it++) {
            if(*it >= ans) ans++;
        }

        cout << ans << endl;

    }
    return 0;
}
