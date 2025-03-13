#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1; //cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n; cin >> n;
        vector<ll> a(n), b(n);
        for(auto &v: a) cin >> v;
        for(auto &v: b) cin >> v;

        map<pair<ll, ll>,ll> mp;
        ll ans = 0, delta = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == 0 && b[i] == 0) {
                delta++;
                continue;
            }

            if(a[i] == 0) continue;

            ll maxi = __gcd(a[i], -b[i]);
            ll na = a[i] / maxi;
            ll nb = -b[i] / maxi;
            mp[{na, nb}]++;
        }
        
        for(auto v: mp) ans = max(ans, v.second);

        ans += delta;

        cout << ans << endl;

        
    }
}