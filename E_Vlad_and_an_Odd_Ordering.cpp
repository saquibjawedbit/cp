#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n, k; cin >> n >> k;
        vector<ll> arr;
        ll j = 1;
        while(n) {
            ll first_round = (n+1)/2;
            if(k <= first_round) {
                break;
            }
            k -= first_round; 
            n =  n/2;
            j *= 2LL;
        }

        ll ans = j * (1LL + 2LL * (k-1LL));
        cout << ans << endl;
    }
}