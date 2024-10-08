#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll k, x, n; cin >> k >> x >> n;
        ll coins = n, spent = 0;

        while(x-- > 0) {
            ll nCoins = spent/(k-1);
            nCoins++;
            spent += nCoins;
            coins -= nCoins;
            if(coins <= 0) {
                break;
            }
        }
        ll nCoins = spent/(k-1) + 1;
        if(nCoins <= coins) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }


    }
}