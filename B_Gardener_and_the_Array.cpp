#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tc = 1; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<vector<ll>> arr(n);
        map<ll, ll> mp;
        for(auto &v: arr) {
            int k; cin >> k;
            while(k-- > 0) {
                ll a; cin >> a;
                v.push_back(a);
                mp[a]++;
            }
        }

        bool ans = false;
        for(int i = 0; i < n; i++) {
            ll cnt = 0;
            for(int j = 0; j < arr[i].size(); j++) {
                if(mp[arr[i][j]] > 1) cnt++;
                
            }
            if(cnt == arr[i].size()) {
                ans = !ans;
                break;
            }
        }

        if(ans) cout << "Yes" << endl;
        else cout << "No" << endl;

        
    }
}