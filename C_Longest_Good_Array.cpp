#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

bool check(ll l, ll r, ll n) {
    ll maxi = l + n * (n + 1)/2;
    if(maxi <= r) return true;
    else return false;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll l,r; cin >> l >> r;
        ll ans = 0;

        ll left = 0, right = 1e9;
        while(right >= left) {
            ll mid = left + (right - left)/2;
            if(check(l, r, mid)) {
                left = mid + 1;
                ans = mid;
            }
            else {
                right = mid - 1;
            }
        }

        cout << ans + 1<< endl;
    }
} 