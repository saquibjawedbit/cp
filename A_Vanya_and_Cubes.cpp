#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    //cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        ll ans = 0;
        while(n > 0) {
            n -= ((ans+1) * (ans+2))/2;
            if(n < 0)  break;
            ans++;
        }

        cout << ans << endl;
    }
} 