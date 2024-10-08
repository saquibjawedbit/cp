#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        if(n&1) {
            ll factor = 1;
            for(ll i = sqrt(n); i >= 2; i--) {
                if(n % i == 0) {
                    //cout << i << " " << (n/i) << endl;
                    factor = max(n/i, i);
                    // break;
                }
            }
            cout << factor << " " << (n-factor) << endl;
        }
        else {
            cout << n/2 << " " << n/2 << endl;
        }
    }
} 
