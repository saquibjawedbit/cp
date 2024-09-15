#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        ll ans = 0;
        ll maxi = 0;
        for(ll i = 2; i <= n; i++) {
            ll j = 1, sum = 0;
            while((j*i) <= n) {
                sum += (j * i);
                j++;

            }
            if(maxi < sum) {
                maxi = sum;
                ans = i;
            }
        }
        cout << ans << endl;
    }
}