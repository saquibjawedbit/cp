#include <bits/stdc++.h>

using namespace std;

#define ll long long




int main() {
    ll tc = 1;
    for(ll t = 1; t <= tc; t++) {
        ll n, m; cin >> n >> m;
        vector<vector<ll>> arr(n, vector<ll>(m, 0));

        for(auto &v: arr) {
            for(auto &s: v) cin >> s;
        }


        map<ll, vector<pair<ll, ll>>> mp;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mp[arr[i][j]].push_back({i+1, j+1});
            }
        }


        ll ans = 0;
        for(auto v: mp) {
            sort(v.second.begin(), v.second.end());

            ll sum = 0;     
            for(auto s: v.second) sum += s.first;
            
            ll index = 1;
            for(auto s: v.second) {
                sum -= s.first;
                ans += llabs((sum - ((v.second.size()-index) * s.first)));
                index++;
            }

            sort(v.second.begin(), v.second.end(),[](pair<ll, ll> first, pair<ll, ll> second) {
                return first.second < second.second;
            });

            sum = 0;
            for(auto s: v.second) sum += s.second;
            index = 1;
            for(auto s: v.second) {
                
                sum -= s.second;
                ans += llabs(sum - ((v.second.size()-index) * s.second));
                index++;
            }
        }

        cout << ans << endl;
        



    }
}