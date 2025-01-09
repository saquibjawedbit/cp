#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);  // Disable sync with C I/O
    cin.tie(nullptr); 
    cout.tie(nullptr);
    ll tc = 1;
    // cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n;
        cin >> n;
        ll ans = 1;

        if(n % 3 == 0) {
            for(ll i = 9; i <= 1e17; i*=3) {
                if(n % i != 0) {
                    ans = n/i + 1;
                    break;
                }
            }
        }
        else {
            ans = n/3 + 1;
        }

        cout << ans << endl;
        
    }
}