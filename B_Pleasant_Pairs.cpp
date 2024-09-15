#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tc = 1; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            ll delta = (arr[i-1] - i);
            while(delta <= i) {
                delta += arr[i-1];
            }
            
            for(int j = delta; j <= n; j+=arr[i-1]) {
                if(arr[i-1] * arr[j-1]  == i+j) ans++;
            }
        }

        cout << ans << endl;
    }
}