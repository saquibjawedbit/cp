#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n,k; cin >> n >> k;
        
        if(k == 1) {
            cout << n << endl;
            continue;
        }

        ll ans = 0;
        while(n != 0) {
            ll left = 0, right = 63;
            while(right >= left) {
                
            }

        }
        cout << ans << endl;       
    }
} 