#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;

    for(ll t = 1; t <= tc; t++) {
        ll k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;


        vector<ll> prs;
        ll pow = 1;
        while (pow <= r2) {
            prs.push_back(pow);
            if (pow > r2 / k) break; 
            pow *= k;
        }

        ll ans = 0;
        for (ll p : prs) {
            ll mini = max(l1, (l2 + p - 1) / p);
            ll maxi = min(r1, r2 / p);

            if (mini <= maxi) ans += (maxi - mini + 1);
            
        }

        cout << ans << endl;
    }

    return 0;
}
