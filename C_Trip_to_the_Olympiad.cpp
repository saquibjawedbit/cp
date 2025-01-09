#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);  // Disable sync with C I/O
    cin.tie(nullptr); 
    cout.tie(nullptr);
    ll tc = 1;
    cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll l, r; cin >> l >> r;

        ll a = 0, b = 0;
        for(int i = 63; i >= 0; i--) {
            ll lower = l & (1ll << i);
            ll upper = r & (1ll << i);

            if(lower != upper) {
                a |= (1ll << i);
                b &= ~(1ll << i);

                for(int j = i - 1; j >= 0; j--) {
                    b |= (1ll << j);
                    a &= ~(1ll << j);
                }
                break;
            }
            else if(lower != 0) {
                a |= (1ll << i);
                b |= (1ll << i);
            }
        }

        ll c = l;
        while(c == a || c == b) c++;

        cout << a << " " << b << " " << c << endl;
       
    }
}