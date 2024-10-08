#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

ll bs(ll k, ll x, bool flag=0) {
    if(x <= 0) return 0;
    ll left = 1ll;
    ll right = k;
    if(flag) right = k-1ll;
    ll ans = 0;
    while(right >= left) {
        ll mid = left + (right - left)/2ll;
        ll sum = 0;
        if(!flag) {
            sum = (mid * (mid + 1))/2;
        }
        else {
            sum = (mid * (2 * left + (mid -1) * -1))/2ll;
        }
        if(sum <= x) {
            ans = mid;
            if(sum < x) ans++;
            left = mid + 1ll;
        }
        else {
            right = mid - 1ll;
        }
    }
    return min(ans, 2ll * k - 1ll);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll k, x; cin >> k >> x;
        ll ans = bs(k, x);
        x = x - (ans * (ans +1ll))/2ll;
        ll left = bs(k,x,1ll);
        ans += left;
        cout << ans << endl;
    }
} 