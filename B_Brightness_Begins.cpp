#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

ll check(ll n) {
    return n - (ll)floor(sqrt(n));
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll k; cin >> k;
        ll left = 0, right = 1e18 + 1e9;
        ll ans = LLONG_MAX;
        while(right >= left) {
            ll mid = left + (right - left)/2;
            ll res = check(mid);
            if(res == k) {
                ans = min(ans, mid);
                right = mid - 1;
            }
            else if(res > k) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        cout << ans << endl;
    }
} 