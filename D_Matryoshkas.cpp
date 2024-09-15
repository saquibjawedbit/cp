#include <bits/stdc++.h>

using namespace std;

#define ll long long

using namespace std;

int main() {
    int tc = 1; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        map<ll, ll> mp;
        for(auto v: arr) mp[v]++;

        ll ans = 0;
        ll prevVal = -1, prevCnt = 0;
        for(auto v: mp) {
            if(v.first == (prevVal + 1)) {
                if(prevCnt < v.second) {
                    ans += v.second - prevCnt;
                }   
            }
            else {
                ans += v.second;
            }
            prevVal = v.first;
            prevCnt = v.second;
        }
        cout << ans << endl;
    }
}