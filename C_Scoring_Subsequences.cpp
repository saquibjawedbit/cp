#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    int tc = 1; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        for(int i = 0; i < n; i++) {
            ll left = 0, right = i;
            ll ans = i;
            while(right >= left) {
                ll mid = (right + left) >> 1;
                ll len = i-mid+1;
                if(len <= arr[mid]) {
                    ans = len;
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            cout << ans << " ";
        } cout << endl;
    }
}