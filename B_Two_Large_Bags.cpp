#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);

        for(auto &v: arr) cin >> v;

        sort(arr.begin(), arr.end());

        map<ll, ll> mp;
        for(int i = 0; i < arr.size(); i++) {
            if(mp[arr[i]] < 2) {
                mp[arr[i]]++;
            }
            else {
                arr[i]++;
                i--;
            }
        }

        bool ans = true;
        for(auto v: mp) {
            if(v.second % 2 != 0) {
                ans = false;
                break;
            }
        }

        if(ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}