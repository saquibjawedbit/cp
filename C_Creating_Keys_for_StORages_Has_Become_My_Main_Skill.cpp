#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n, x; cin >> n >> x;

        vector<ll> a(n, 0);
        ll currentNum = 0;
        for(ll i = 0 ; i <= 63; i++) {
            ll lastBit = x & (1LL << i);
            if(lastBit != 0) {
                ll delta = (1ll << (i+1));
                ll cnt = 0;
                //cout << delta << endl;
                for(int j = 0; j < n; j+=delta) {
                    for(int k = j + delta/2; k < min(j + delta, n); k++) {
                        a[k] = a[k] ^ (1ll << i);
                        cnt++;
                    }
                }

                if(cnt == 0) {
                    a.back() = a.back() ^ (1ll << i);
                }
            }
        }

        for(auto v: a) cout << v << " ";
        cout << endl;
    }
}