#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tc = 1; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> a(n), b(n);
        for(auto &v: a) cin >> v;
        for(auto &v: b) cin >> v;

        vector<pair<ll, ll>> mp;

        for(int i = 0; i < n; i++) {
            ll val = a[i] - b[i];
            mp.push_back({val, i+1});
        }

        sort(mp.begin(), mp.end(), greater<pair<ll, ll>>());

        vector<ll> ans;
        ll maxi = mp[0].first;
        for(auto &v: mp) {
            if(maxi == v.first) ans.push_back(v.second);
            else break; 
        }
        
        cout << ans.size() << endl;
        for(int i = ans.size()-1; i >= 0; i--) cout << ans[i] << " ";
        cout << endl; 

    }
}