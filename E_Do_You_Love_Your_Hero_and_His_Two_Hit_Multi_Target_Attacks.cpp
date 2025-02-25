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

        if(k == 0) {
            cout << 2 << endl;
            cout << "0 100" << endl;
            cout << "1 401" << endl;
        }

        if(k == 1) {
            cout << 2 << endl;
            cout << "0 100" << endl;
            cout << "0 101" << endl;
        }
        
        vector<pair<ll,ll>> ans; ll count  = 0;
        for(int i = 0; i <= 500; i++) {
            ll delta = 0;
            for(int j = i+1; j <= 500; j++) {
                ans.push_back({i,j});
                count += delta;
                delta += 1;
                
                if(count == k) {
                    break;
                }
                else if(count+ delta > k) {
                    break;
                }
            }

            if(count == k) break;
        }

        cout << ans.size() << endl;
        for(auto &v: ans) {
            cout << v.first << " " << v.second << endl;
        }

    
    }
}