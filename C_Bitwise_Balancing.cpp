#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll b, c, d; cin >> b >> c >> d;
        ll ans = 0;
        for(ll i = 63; i >= 0; i--) {
            ll dbit = (d & (1ll << i));
            ll bbit = (b & (1ll << i));
            ll cbit = (c & (1ll << i));
            
            if(dbit != 0 && bbit == 0) {
                ans = ans ^ (1ll << i);
            }
            else if(bbit != 0 && dbit == 0) {
                ans = ans ^ (1ll << i);
            }
            
        }
        if(((ans | b) - (ans & c)) != d) {
            ans = -1;
        }
        cout << ans << endl;
    }
} 