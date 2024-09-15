#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t1  =1; t1 <= tc; t1++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(ll i = 0; i < n; i++) cin >> arr[i];

        if(n <= 2) {
            cout << 0 << endl;
            continue;
        }

        ll ans = 0;
        ll sl = INT_MAX;
        ll tl = INT_MAX;
        for(ll i = 0; i < n; i++) {

            if(sl > tl) swap(sl, tl);

            if(arr[i] <= sl) sl = arr[i];
            else if(arr[i] <= tl) tl = arr[i];
            else {
                ans++;
                sl = arr[i];
            }
        }



        cout << ans << endl; 
    }
}