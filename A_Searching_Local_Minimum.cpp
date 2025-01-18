#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

int main() {

    // ios_base::sync_with_stdio(false);  // Disable sync with C I/O
    // cin.tie(nullptr); 
    // cout.tie(nullptr);
    ll tc = 1;
    // cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n; cin >> n;

        ll right = n, left = 1;
        ll ans = -1;
        while(right >= left) {
            ll mid = (right+left)/2;
            cout << "? " << mid << endl;
            ll q1; cin >> q1;
            if(mid+1 > n) {
                ans = mid;
                break;
            }
            cout << "? " << mid+1 << endl;
            ll q2; cin >> q2;
            if(q1 < q2) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }

        cout << "! " << ans << endl;       
    }
}