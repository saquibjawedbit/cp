#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ll tc = 1; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        ll n; cin >> n;
        ll ans = 1;
        for(ll i = 2; i <= 1e9; i++) {
            if((n % i ) == 0) ans++;
            else break;
        }

        cout << ans << endl;
    }
}