#include <bits/stdc++.h>


using namespace std;

#define ll long long
#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);  // Disable sync with C I/O
    cin.tie(nullptr); 
    cout.tie(nullptr);
    ll tc = 1;
    // cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        auto check = [&](ll x) -> bool {
         
            ll cnt = 0;
            for(auto v: arr) {
                cnt += (x / v);
                if(cnt >= k) return true;
            }
            return (cnt >= k);
        };

        // cout << check(500000000000000000ll) << endl;
        ll left = 1, right = 1e18;
        ll ans = 0;
        while(right >= left) {
            ll mid = left + (right - left) / 2;
            
            if(check(mid)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }

        cout << ans << endl;
       
    }
}