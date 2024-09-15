#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll a, b, r; cin >> a >> b >> r;


        //a is alway greater
        if(b > a) swap(a, b);
        ll ans = abs(a - b);
        
    
        ll n1 = (r == 0) ? 0 : 63 - __builtin_clzll(r);
        ll n2 = (a == 0) ? 0 : 63 - __builtin_clzll(a);

        bool isDiff = false;

        ll bitmask = 0;
        for(ll i = n2; i >= 0; i--) {
            if(b > a) {
                swap(a, b); 
            }

            ll aBit = a & (1LL << i);
            ll bBit = b & (1LL << i);

            if(aBit > bBit && isDiff) {
                ll n_b = bitmask ^ (1LL << i);
                if(n_b > r) continue;
                b = b ^ (1LL << i);
                a = a ^ (1LL << i);
                bitmask = n_b;
            }
            else if(aBit > bBit && !isDiff) isDiff = true;

            if(bitmask <= r) ans = min(ans, abs(b - a));
            if(bitmask > r) break;
        }

        cout << ans << endl;
    }
}