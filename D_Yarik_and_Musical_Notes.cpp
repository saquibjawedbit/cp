#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 0; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        int n; cin >> n;
        vector<ll> arr(n, 0);
        for(int i = 0; i < n; i++) cin >> arr[i];
        unordered_map<double, ll> mp;
        ll ans = 0;
        for(ll i = 0; i < n; i++) {
            double key = log2(arr[i]) - arr[i];
            //cout << key << endl;
            ans += mp[key];
            mp[key]++;
        }

        cout << ans << endl;
    }
}