#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n, k; cin >> n >> k;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        sort(arr.begin(), arr.end(), greater<ll>());

        ll sum = 0;
        ll ans = 0;
        for(auto v: arr) {
            if((sum + v) == k) {
                sum+= v;
                break;
            }
            else if((sum + v) > k) {
                ans = (k - sum);
                break;
            }
            else {
                sum += v;
            }   
        }

        if(sum < k) {
            ans = k - sum;
        }

        cout << ans << endl;
    }
}