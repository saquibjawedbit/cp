#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n, x, y; cin >> n >> x >> y;

        ll cnt1 = n/x - n/lcm(x,y);
        ll cnt2 = n/y - n/lcm(x,y);

        //cout << cnt1 << " " << cnt2 << endl;


        ll ans = (n * (n+1))/2 - ((n - cnt1)*(n - cnt1 + 1))/2 - (cnt2 * (cnt2+1))/2;
        cout << ans << endl;
    }
}