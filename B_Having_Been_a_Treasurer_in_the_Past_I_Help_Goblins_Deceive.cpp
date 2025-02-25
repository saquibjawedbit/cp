#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n; cin >> n;
        string s; cin >> s;

        ll dash = 0, u = 0;

        for(auto v: s) {
            if(v == '_') u++;
            else dash++;
        }

        if(dash%2 == 0) {
            cout << (dash/2 * u * dash/2) << endl;
        }
        else {
            cout << ((dash/2 * u * (dash+1)/2)) << endl;
        }
    }
}