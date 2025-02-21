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
        ll x, y; cin >> x >> y;

        if(x + 1 >= y && (x - y + 1ll) % 9 == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

