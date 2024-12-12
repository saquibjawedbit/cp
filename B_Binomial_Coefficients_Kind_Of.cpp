#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007


ll power(ll base, ll exp) {
    ll result = 1;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = ((result % MOD) * (base % MOD)) % MOD; 
        }
        base =  ((base % MOD) * (base % MOD)) % MOD;       
        exp /= 2;       
    }
    return (result % MOD);
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;

    for(ll t1 = 1; t1 <= tc; t1++) {
        ll t; cin >> t;
        vector<ll> n(t), k(t);
        for(auto &v: n) cin >> v;
        for(auto &v: k) cin >> v; 

        for(int i = 0; i < t; i++) {
            ll ans = (power(2, k[i])) % MOD;
            cout << ans << endl;
        }
    }
} 