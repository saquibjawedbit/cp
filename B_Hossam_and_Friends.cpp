#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n, m; cin >> n >> m;

        vector<pair<ll, ll>> arr(m);
        for(auto &v: arr) {
            ll a, b; cin >> a >> b;
            v.first = min(a, b);
            v.second = max(a, b);
        }

        sort(arr.begin(), arr.end());

        ll ans = 0;
        ll index = arr.size()-1, right = n;
        for(ll i = n; i > 0; i--) {
            while(index >= 0 && arr[index].first == i) {
                right = min(right, arr[index].second-1ll);
                index--;    
            }
            
            ans += (right - i + 1);

        }

        cout << ans << endl;
    }
}