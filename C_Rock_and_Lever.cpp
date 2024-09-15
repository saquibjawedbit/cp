#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        int n; cin >> n;
        vector<long long> arr(n, 0);
        for(int i = 0; i < n; i++) cin >> arr[i];

        map<long long, long long> mp;
        for(auto v: arr) {
            int value = -1;
            while(v != 0) {
                value++;
                v = v >> 1;
            }
            mp[value]++;
        }

        long long ans = 0;
        for(auto v: mp) {
            //cout << v.first << " " << v.second << endl;
            ans += v.second * (v.second-1) /2;
        }

        cout << ans << endl;
    }
}