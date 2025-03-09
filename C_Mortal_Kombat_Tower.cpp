#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll solve(vector<ll> &arr, ll index, vector<vector<vector<ll>>>  &dp, bool turn = 0, ll conc = 0) {
    if(index >= arr.size()) {
        return 0;
    }

    if(dp[index][turn][conc] != -1) return dp[index][turn][conc];

    ll left = INT_MAX, right = INT_MAX;
    
    if(conc == 2) {
        return dp[index][turn][conc] = solve(arr, index, dp, !turn, 0);
    }

    left = solve(arr, index+1, dp, !turn, 0) + (arr[index] == 1 && turn == 0);
    right = solve(arr, index+1,dp, turn, conc+1) + (arr[index] == 1 && turn == 0);

    return dp[index][turn][conc] = min(left, right);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n; cin >> n;
        vector<ll> arr(n);

        for(auto &v: arr) cin >> v;

        vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(2, vector<ll>(3, -1)));

        ll ans = solve(arr, 0, dp);
        cout << ans << endl;
    }
}