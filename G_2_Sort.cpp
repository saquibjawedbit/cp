#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n, k; cin >> n >> k;
        vector<ll> arr(n);

        for(auto &v: arr) cin >> v;

        ll len = 1, ans = 0;
        for(ll i = 1; i < n; i++) {
            ll val = arr[i-1]/arr[i];
            if(val <= 1) {
                len++;
            }
            else {
                ans += max(len - k, 0ll);
                len = 1;
            }
        }
     
        ans += max(len - k, 0ll);
        cout << ans << endl;
    }

}