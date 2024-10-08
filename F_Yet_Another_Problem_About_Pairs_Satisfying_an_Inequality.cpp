#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        vector<pair<ll, ll>> np;  
        for(int i = 0; i < n; i++) {
            if(arr[i] < (i+1)) {
                np.push_back({arr[i], i+1});        
            }
        }

        sort(np.begin(), np.end());
        ll ans = 0;

        for(auto v: np) {
            ll ai = v.first;
            ll i = v.second;

            auto upr = upper_bound(np.begin(), np.end(), make_pair(i, -1ll)) -np.begin();

            while(upr < np.size() && np[upr].first == v.second) {
                upr++;
            }

            if(upr < np.size()) {
                ans += np.size() - upr;
                // cout << np.size()-upr << endl;
            }
        } 

        cout  << ans << endl;
    }
}