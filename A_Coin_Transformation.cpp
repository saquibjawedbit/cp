#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n; cin >> n;
        ll cnt = 0;

        while(n > 0) {
            cnt ++;
            n = n/4;
        }

        // cout << cnt << endl;

        cout << (ll)pow(2, cnt-1) << endl;
    }
}