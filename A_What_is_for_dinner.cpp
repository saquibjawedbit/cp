#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    map<ll, ll> mp;
    for(ll i = 1; i <= n; i++) {
        ll r, c; cin >> r >> c;
        if(mp.find(r) == mp.end()) {
            mp[r] = c;
        } else {
            mp[r] = min(mp[r], c);
        }
    }

    ll ans = 0;
    for(auto &[key, value]: mp) {
        ans += value;
    }

    ans = min(ans, k);

    cout << ans << endl;
}