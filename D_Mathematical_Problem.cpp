#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007


ll solve(string &s, int st, int index, bool lastOperation, vector<vector<ll>> &dp) {
    if(index >= s.length()) return lastOperation;

    if(dp[index][lastOperation] != -1) return dp[index][lastOperation];

    if(index == st) {
        ll mult = solve(s, st, index+2, 1, dp) * stoi(s.substr(st, 2));
        ll add = solve(s, st, index+2, 0, dp) + stoi(s.substr(st,2));
        dp[index][lastOperation] = min(mult, add);
        return min(mult, add);
    }

    ll mult = solve(s, st, index+1, 1, dp) * (s[index] - 48);
    ll add = solve(s, st, index+1, 0, dp) + (s[index]-48);
    dp[index][lastOperation] = min(mult, add);
    return min(mult, add);
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        string s; cin >> s;

        ll ans =INT_MAX;
        for(int i = 0; i < n-1; i++) {
            vector<vector<ll>> dp(n+1, vector<ll>(3, -1));
            ans = min(ans, solve(s, i, 0, 0, dp));
        }

        cout << ans << endl;

    }
}