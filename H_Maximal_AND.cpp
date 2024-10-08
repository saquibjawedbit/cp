#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n, k; cin >> n >> k;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        ll ans = 0;
        for(int i = 30; i >= 0; i--) {
            ll req = 0;
            for(int j = 0; j < arr.size(); j++) {
                if((arr[j] & (1 << i)) == 0) req++;
            }
            // cout << i << " " << req << endl;
            if(k >= req) {
                k -= req;
                ans = (ans ^ (1 << i));
            }
        }
        cout << ans << endl;        
    }
} 