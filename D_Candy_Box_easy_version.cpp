#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        map<ll, ll> cnt;
        for(auto v: arr) cnt[v]++;

        map<ll, bool> isPresent;
        ll ans = 0;
        for(auto v: cnt) {
            // cout << v.first << " " << v.second << endl;
            if(!isPresent[v.second]) {
                ans+=v.second;
                isPresent[v.second] = 1;
            }
            else {
                while(isPresent[v.second] && v.second > 0) v.second--;

                if(!isPresent[v.second] && v.second > 0) {
                    ans += v.second;
                    isPresent[v.second] = 1;
                }
            }
        }

        cout << ans << endl;
    }
}