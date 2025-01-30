#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n, k; cin >> n >> k;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        sort(arr.begin(), arr.end());

        ll ans = 0;
        map<ll, ll> mp;
        for(auto v: arr) {
            ll req = k - v;
            if(mp.find(req) != mp.end() && mp[req] > 0) {
                ans++;
                mp[req]--;
            }
            else {
                mp[v]++;
            }
        }

        cout << ans << endl;
    }
}