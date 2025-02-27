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
        ll k; cin >> k;

        vector<pair<ll,ll>> ans;
        ll cnt = 0; ll dm = 0;
        for(ll i = 0; i <= 500; i++) {
            ll delta = 0;
            for(ll j = dm; j <= 500; j++) {
                ans.push_back({i,j});
                cnt += delta;
                delta++; dm++;
                if(cnt + delta > k) {
                    break;
                }

                if(cnt == k) {
                    break;
                }
            }
            if(cnt == k) {
                break;
            }
        }

        cout << ans.size() << endl;
        for(auto p : ans) {
            cout << p.first << " " << p.second << endl;
        }

    
    }
}