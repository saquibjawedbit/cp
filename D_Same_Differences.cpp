#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    int tc = 1; cin >> tc;
    for(int t =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        ll ans = 0;
        map<ll, ll> mp;
        for(int i = 0; i < n; i++) {
            ll diff = arr[i] - i;
            ans += mp[diff];
            mp[arr[i]-i]++;
        }

        cout << ans << endl;


    }
}