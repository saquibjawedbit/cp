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

        sort(arr.begin(), arr.end());

        auto check = [&](ll mid) {
            ll cnt = 0;
            for(ll i = n/2; i < n; i++) {
                if(mid - arr[i] > 0) {
                    cnt += mid - arr[i];
                }
            }
            return cnt <= k;
        };


        ll left = 0, right = 1e10;
        ll ans = 0;
        while(right >= left) {
            ll mid = left + (right -left)/2;
            if(check(mid)) {
                left = mid +1;
                ans = mid;
            }
            else {
                right = mid -1;
            }
        }
        cout << ans << endl;
    }
}