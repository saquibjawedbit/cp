#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        bool isRemoved = false;
        vector<pair<ll,ll>> nArr(n+1, {0, 0});
        nArr[1] = {arr[0], 0};
        ll prev = arr[0];
        ll index = 1;
        for(auto v: arr) {
            if(prev != v) index++;

            nArr[index] = {v, nArr[index].second+1};
            prev = v;
        }


        ll ans = 0;
        for(int i = 1; i < n; i++) {
            if(nArr[i].second == 0) break;

            if(nArr[i].first == 1) {
                ans = max(ans, nArr[i].second);
                continue;
            }
            else if(nArr[i].first == 0 && nArr[i+1].first == 1 && nArr[i-1].first == 1 && nArr[i].second == 1) {
                ans = max(ans, nArr[i+1].second + nArr[i-1].second);
                isRemoved = true;
            }
            else {
                isRemoved = true;
            }
        }

        if(!isRemoved ) ans--;
        cout << ans << endl;
    }
    return 0;
}