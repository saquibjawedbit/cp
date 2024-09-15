#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

ll gcd(ll a, ll b) {

}



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll l, r; cin >> l >> r;
        ll ans = 0;
        for(ll i = l; i <= r; i++) {

            if((r - i) < 2) break;

            if((i&1)) {
                ans++;
                i+=2;
            } 
        }
        cout << ans << endl;
       
    }
} 