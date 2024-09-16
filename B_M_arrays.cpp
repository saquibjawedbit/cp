#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    int tc = 1; cin >> tc;
    for(int t  = 1; t <= tc; t++) {
        ll n, m; cin >> n >> m;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        //for(auto &v: arr) v = v % (m+1);
        ll ans = 0;
        map<ll, ll> mp;
        for(auto v: arr) {
            mp[v%m]++;
        }


        if(mp[0] != 0) ans++;
        mp[0] = 0;


        for(auto v: mp) {
            if(v.second == 0) continue;
            ll nv =  v.first;
            if(mp[(m-nv) % m] != 0) {
                ll mini = min(mp[(m- nv)], mp[nv]);
                ll maxi = max(mp[(m- nv)], mp[nv]);

                if(mini == maxi || mini + 1 == maxi) {
                    ans++;
                }
                else {
                    ans += abs(maxi - mini);
                }
                mp[(m-nv)] = 0; mp[nv] = 0;
            } else {
                ans+=v.second;
            }
        }
        cout << ans << endl;
        
    }
}