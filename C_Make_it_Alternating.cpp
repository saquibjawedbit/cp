#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;

ll permute(ll n) {
    ll res = 1;
    for(int i = n; i >= 1; i--) res = ((res % mod) * (i % mod)) % mod;
    return res;
}



int main() {
    int tc = 1; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        string s; cin >> s;
        vector<ll> arr;
        for(int i = 0; i < s.length(); i++) {
            ll cnt = 1;
            while(i+1 < s.length() && s[i] == s[i+1]) {
                cnt++;
                i++;
            }
            arr.push_back(cnt);
        }

        ll pos = 0;
        ll ans = 1;
        for(auto v: arr) {
            pos += (v-1);
            if(v > 1) {
                ans = ((ans % mod) * (v % mod)) % mod;
            }
        }


        cout << pos << " " << ((ans % mod) * permute(pos % mod) % mod) % mod << endl;
        
    }
}