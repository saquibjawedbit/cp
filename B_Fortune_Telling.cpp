#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t; cin >> t;
    while (t--) {
        ll n, x, y; 
        cin >> n >> x >> y;
        vector<ll> a(n);
        ll xor_a = 0;

        for (ll &val : a) {
            cin >> val;
            xor_a ^= val;
        }


        ll sum = xor_a + x;

        if((sum&1) == (y&1)) cout << "Alice" << endl;
        else cout << "Bob" << endl;

    }
    return 0;
}
