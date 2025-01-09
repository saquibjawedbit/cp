#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);

        for(auto &v: arr) cin >> v;
        ll ans = 0;
        for(int i = 1; i < n; i++) {
            ll diff = arr[i-1] - arr[i];

            if(diff > 0) {
                ll bits = 64 - __builtin_clzll(diff);
                ans = max(ans, bits);
                arr[i] = arr[i-1]; 
            } 
        }

        cout << ans << endl;


    }
}