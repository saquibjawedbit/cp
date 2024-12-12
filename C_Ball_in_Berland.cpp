#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc= 1; cin >> tc;
    for(ll t =1; t <= tc; t++) {
        ll a, b, k; cin >> a >> b >> k;
        vector<pair<ll, ll>> arr(k);

        for(auto &v: arr) cin >> v.first;
        for(auto &v: arr) cin >> v.second;

        map<ll, ll> aC, bC;
        ll ans = 0;

        for(auto &v: arr) {
            aC[v.first]++; bC[v.second]++;
        }

        for(auto &v: arr) {
            ans += k - (aC[v.first] + bC[v.second]-1);
            aC[v.first]--; bC[v.second]--;
            k--;
        }

        cout << ans << endl;
    }
}