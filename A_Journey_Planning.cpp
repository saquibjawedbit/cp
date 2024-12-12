#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ll tc = 1;
    for(ll t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);

        for(auto &v: arr) cin >> v;
        
        map<ll ,ll> mp;
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]-i-1] += arr[i];
        } 

        ll ans = 0;
        for(auto v: mp) {
            // cout << v.first << " " << v.second << endl;
            ans = max(ans, v.second);
        }

        cout << ans << endl;
    }
    return 0;
}