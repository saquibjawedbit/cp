#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        vector<ll> arr(3);
        for(ll i = 0; i < 3; i++) cin >> arr[i];
        ll k; cin >> k;
        ll v = 1;
        for(ll i = 0; i < 3; i++) v *= arr[i];
        
        if(v < k) {
            cout << 0 << endl;
            continue;
        }
        else if(v == k) {
            cout << 1 << endl;
            continue;
        }

        ll ans = 0;
        for(ll i = 1; i <= arr[0]; i++) {
            for(ll j = 1; j <= arr[1]; j++) {
                double k1 = (double)k/(i * j);
                ll k2 = k1;
                if(k1 == k2) {
                   // cout << i << " " << j << " " << k1 << endl;
                    ll temp = (arr[0]-i+1) * (arr[1]-j+1) * (arr[2]-k2+1);
                    ans = max(ans, temp);
                }
            }
        }

        cout << ans << endl;
       
    }
}