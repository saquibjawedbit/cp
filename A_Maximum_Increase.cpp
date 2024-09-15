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
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        int ans = 1, currMax = 0, prev = -1;

        for(auto &v: arr) {
            if(v > prev) {
                currMax++;
            } else {
                ans = max(ans, currMax);
                currMax = 1;
            }
            prev = v;
        }
        ans = max(ans, currMax);
        cout << ans << endl;
    }
} 