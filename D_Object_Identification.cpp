#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        cout << "? 1 " << n << endl;
        ll a, b; cin >> a;
        cout << "? " << n << " 1" << endl;
        cin >> b;

        
        if(a != 0 && b != 0 && a == b) {
            cout << "! B" << endl;
        }
        else {
            cout << "! A" << endl;
        }
    }
}