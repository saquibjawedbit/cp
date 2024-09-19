#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tc = 1; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        ll n, x, y; cin >> n >> x >> y;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        ll ans = 0;
        map<pair<ll,ll>, ll> mp;
        for(auto v: arr) {
            ll add = (x - v % x) % x;
            ll sub = v % y;
            //cout << v << " " << add << " " << sub << endl;
            if(mp[{add, sub}] != 0)  {
                ans += mp[{add, sub}];
            }
            mp[{v%x, v%y}]++;
        }

        cout << ans << endl;
    }
}