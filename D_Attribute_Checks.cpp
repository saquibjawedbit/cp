#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007


ll solve(vector<ll> &arr, ll index, ll inte, ll strength, map<ll,map<ll, ll>>& dp) {
    if(index >= arr.size()) return 0;

    if(dp.find(index) != dp.end() && dp[index].find(inte-strength) != dp[index].end()) {
        //cout << "HEllo" << endl;
        return dp[index][inte-strength];
    }

    if(arr[index] == 0) {
        ll left = solve(arr, index+1, inte+1, strength, dp);
        ll right = solve(arr, index+1, inte, strength+1, dp);
        dp[index][inte-strength] = max(left, right);
        return max(left, right);
    }
    else if(arr[index] > 0 && arr[index] <= inte) {
        dp[index][inte-strength] = solve(arr, index+1, inte, strength, dp) + 1;
        return dp[index][inte-strength];
    }
    else if(arr[index] < 0 && abs(arr[index]) <= strength) {
        dp[index][inte-strength] = solve(arr, index+1, inte, strength, dp) + 1;
        return dp[index][inte-strength];
    }

    dp[index][inte-strength] =  solve(arr, index+1, inte, strength, dp);
    return dp[index][inte-strength];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
    //cin >> tc;
    for (ll t1 = 1; t1 <= tc; t1++)
    {
        ll n, m; cin >> n >> m;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;
        map<ll,map<ll, ll>> dp;

        ll ans = solve(arr, 0, 0, 0, dp);
        cout << ans << endl;
    }
}