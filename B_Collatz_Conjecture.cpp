#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll x, y, k; cin >> x >> y >> k;
        vector<ll> arr;
        while(x) {
            arr.push_back(x % y);
            x = x/y;
        }

        ll ans = 0;
        for(ll i = 0; i < arr.size(); i++) {
            ll diff = y - arr[i];
            if(diff <= k) {
                k -= diff;
                arr[i] = 0;
                if(i+1 < arr.size()) arr[i+1]++;
            }
            else {
                arr[i] += k;
                k = 0;
                for(ll j = arr.size()-1; j >= i; j--) {
                    ans = ans * y + arr[j];
                }
                break;
            }

            if(i == arr.size()-1) {
                ans = k % (y-1) + 1;
                break;
            }
        }
        cout << ans << endl;
    }
}