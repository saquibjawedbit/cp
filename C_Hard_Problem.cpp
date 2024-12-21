#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll m, a, b, c; cin >> m >> a >> b >> c;

        ll ans = min(m, a) + min(m, b);

        ll totalSeat  = 2 * m- ans;

        ans += min(totalSeat, c);
        cout << ans << endl;
    }
}