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
        ll n; cin >> n;

        auto check = [&](ll mid) {
            ll cnt = 0;
            for(ll i = 1; i <= n; i++) {
                cnt += min(mid/i, n);
            }
            return cnt;
        };

        ll k = (n*n + 1) / 2;

        ll left = 1, right = n*n;
        ll ans = 0;
        while(right >= left) {
            ll mid = (left + right) / 2;
            if(check(mid) < k) {
                left = mid + 1;
            } else {
                ans = mid;
                right = mid-1;
            }
        }

        cout << ans << endl;
    }
}