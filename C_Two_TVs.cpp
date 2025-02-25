#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1; // cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n; cin >> n;
        vector<pair<ll,ll>> arr(n);

        for(auto &v: arr) cin >> v.first >> v.second;

        sort(arr.begin(), arr.end());

        vector<pair<ll,ll>> tv1, tv2;
        bool ans = 1;

        for(int i = 0; i < arr.size(); i++) {
            if(tv1.empty()) {
                tv1.push_back(arr[i]);
            }
            else if(tv1.back().second < arr[i].first) {
                tv1.push_back(arr[i]);
            }
            else if(tv2.empty() || tv2.back().second < arr[i].first) {
                tv2.push_back(arr[i]);
            }
            else {
                ans = 0;
                break;
            }
        }

        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}