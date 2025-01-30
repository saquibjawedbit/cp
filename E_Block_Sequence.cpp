#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll solve(vector<ll> &arr, ll index, map<ll, ll> &dp) {
    if(index >= arr.size()) return 0;

    if(dp.find(index) != dp.end()) return dp[index];

    ll ans = 0;
    ll incl = INT_MAX, excl = INT_MAX;
    // cout << index + arr[index] + 1 << endl;
    if(index+arr[index]+1 <= arr.size()) {
        incl = solve(arr, index + arr[index]+1, dp);
    }
    excl = solve(arr, index + 1, dp) + 1;

    dp[index] = min(incl, excl);

    return dp[index];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n; cin >> n;
        vector<ll> arr(n);

        for(auto &v: arr) cin >> v;
        map<ll, ll> dp;
        ll ans = solve(arr, 0, dp);
        cout << ans << endl;

    }
}