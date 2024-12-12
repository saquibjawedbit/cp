#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll cntZeroes(ll val) {
    ll cnt = 0;
    for(ll i = 10;  i <= 1e9; i*=10) {
        if(val % i == 0) cnt++;
        else return cnt;
    }

    return cnt;
}

int main() {
    ll tc = 1; cin >> tc;
    for(ll t= 1; t <= tc; t++) {
        ll n, m; cin >> n >> m;

        ll ans = 1;
        while(n % 10 == 0) {
            n /= 10;
            ans *= 10;
        }

    
        while(n % 5 == 0 && m >= 2) {
            n /= 5;
            m /= 2;
            ans *= 10;
        }

        while(n % 2 == 0 && m >= 5) {
            n /= 2;
            m /= 5;
            ans *= 10;
        }

        while(m >= 10) {
            m /= 10;
            ans *= 10;
        }

        ans = ans * n * m;

        cout << ans << endl;
    }
}