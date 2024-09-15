#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    map<int, int> mp;
    int ans = 0;
    for(auto v: arr) {
        if(mp[v] == 0) {
            ans++;
            int r = (v ^ INT_MAX);
            mp[r]++;
        }
        else {
            mp[v]--;
        }
    }

    cout << ans << endl;

}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();
}