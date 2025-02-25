#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n, k, p; cin >> n >> k >> p;

        if(k == 0) {
            cout << 0 << endl;
            continue;
        }
        
        if(k < 0) k = -k;

        ll req = p * n;

        if(req >= k) {
            ll ans = k/p;
            if(k % p != 0) {
                ans++;
            }
            cout << ans << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}