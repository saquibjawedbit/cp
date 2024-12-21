#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n; cin >> n;

        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if((i+j) == n) ans++;
            }
        }

        cout << ans << endl;
    }
}