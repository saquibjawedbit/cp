#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    //cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        if(n&1) {
            if(n== 1) {
                cout << 4 << endl;
                continue;
            }

            ll nEven = (n-2ll)/2 + 1;
            ll a = 2, b= 1;
            a += nEven; b+=nEven;
            cout << ((a * b) << 1) << endl;
        }
        else {
            ll nOdd = (n-1ll)/2 + 1;
            ll k = 2 + nOdd;
            cout << (((k-1) * (k-1))) << endl;
        }

    }
} 
