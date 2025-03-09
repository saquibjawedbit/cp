#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here

        ll k; cin >> k;

        double n = (k-1)/3.0 + 1;

        // cout << n << endl;

        if(n == (ll)n) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        
    }
}