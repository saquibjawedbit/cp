#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<long long> arr(n, 0);
    for(int i = 0; i < n; i++) cin >> arr[i];

    long long sum = 0;
    map<long long, bool> mp;

    for(int i = 0; i < n; i++) {
        if(i&1) sum += arr[i];
        else sum -= arr[i];

        if(mp[sum] || sum == 0) {
            cout << "YES" << endl;
            return;
        }
        else mp[sum] = 1;
    }

    cout << "NO" << endl;
}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();
}