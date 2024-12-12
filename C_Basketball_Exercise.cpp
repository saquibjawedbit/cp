#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll solve(vector<pair<ll, ll>> &arr, ll index, bool second, vector<vector<ll>> &dp) {
    if(index >= arr.size()) return 0;

    if(dp[index][second] != -1) {
        return dp[index][second];
    }

    ll incl = 0, excl = 0;
    if(second) {
        incl = solve(arr, index+1, !second, dp) + arr[index].second;
        excl = solve(arr, index+1, second, dp);

    }
    else {
        incl = solve(arr, index+1, !second, dp) + arr[index].first;
        excl = solve(arr, index+1, second, dp);
    }

    dp[index][second] = max(incl, excl);

    return max(incl, excl);
}

int main() {
    ll n; cin >> n;
    vector<pair<ll,ll>> arr(n);

    for(auto &v: arr) cin >> v.first;
    for(auto &v: arr) cin >> v.second;

    vector<vector<ll>> dp(n+1, vector<ll>(2, -1));
    ll ans = max(solve(arr, 0, 0, dp), solve(arr, 0, 1, dp));

    cout << ans << endl;
}