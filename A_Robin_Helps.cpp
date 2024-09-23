#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    int tc= 1;
    cin >> tc;
    for(int t =1; t <= tc; t++) {
        ll n, k; cin >> n >> k;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        ll ans = 0;
        ll currGold = 0;
        for(auto v: arr) {
            if(v >= k) {
                currGold += v;
            }
            else if(v == 0 && currGold > 0) {
                currGold--;
                ans++;
            }
        }
        cout << ans << endl;

    } 

}