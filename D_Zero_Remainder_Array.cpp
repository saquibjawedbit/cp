#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n, k; cin >> n >> k;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        map<ll, ll> mp;
        for(auto &v: arr) {
            v = v % k;
            mp[v]++;
        }

        // ll ans = 0;
        // ll prevFreq = 0, index = 1;
        // for(auto &[key, freq]: mp) {
        //     if(key == 0) continue;
        //     if(freq > prevFreq) {
        //         ll a = (k*index) - key;
        //         freq -= prevFreq;
        //         ll an = (a-ans) + (freq-1ll) * k;
        //         ans += an;
        //         prevFreq = freq;
        //         index++;
        //     } 
        //     else {
        //         break;
        //     }
        // }
        // if(prevFreq == 0) cout << 0 << endl;
        // else cout << ans+1 << endl;

        ll maxiValue = INT_MIN; ll maxiKey = INT_MIN;
        for(auto &[key, value]: mp) {
            if(value > maxiValue && key != 0) {
                maxiValue = value;
                maxiKey = key;
            }
            else if(value == maxiValue && key != 0) {
                if(key < maxiKey) maxiKey = key;
            }
        }
        
        ll ans = (k-maxiKey) + (maxiValue - 1ll) * k + 1ll;
        if(maxiKey == INT_MIN) ans = 0;
        cout << ans << endl;

    }
}