#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tc = 1; cin >> tc;
    for(int t= 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;
        unordered_map<ll, ll> mp;

        ll ans = 0;

        for(auto v: arr) {
            ll cnt = 63 - __builtin_clz(v);
            ans += mp[cnt];
            mp[cnt]++;
        }

        cout << ans << endl;
    }
}