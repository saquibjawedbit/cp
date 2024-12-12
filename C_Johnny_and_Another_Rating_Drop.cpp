#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n; cin >> n;
        ll ans = 0;
        int leading_zeroes = 64 - __builtin_clzll(n);
        for(ll i = 0; i <= leading_zeroes; i++) {
            ans += n;
            n /= 2;
        }

        cout << ans << endl;
    }
}