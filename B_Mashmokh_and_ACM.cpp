#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9+7; 

ll solve(ll n, ll curr, ll len, ll maxLen, vector<vector<ll>> &dp) {
    if(len == maxLen) {
        return 1;
    }

    if(dp[len][curr] != -1) {
        return dp[len][curr];
    }

    ll ans = 0;
    for(ll i = curr; i <= n; i+=curr) {
        if(i % curr == 0) {
            ans = (ans % MOD + solve(n, i, len+1, maxLen, dp) % MOD) % MOD;
        }
    }

    dp[len][curr] = ans;  
    return ans;
}

int main() {
    ll n, k; cin >> n >> k;

    ll ans = 0;
    vector<vector<ll>> dp(k+1, vector<ll>(n+1, -1));
    ans = solve(n, 1, 0, k, dp);

    cout << ans << endl;
}