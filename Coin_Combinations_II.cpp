#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

vector<ll> arr; // Global array to avoid passing repeatedly

ll solve(ll currentSum, vector<ll> &dp) {
    if (currentSum == 0) return 1; // 1 way to make sum 0 (take nothing)
    if (currentSum < 0) return 0;  // No way to make a negative sum

    if (dp[currentSum] != -1) return dp[currentSum]; // Return cached result

    ll ways = 0;
    for (ll num : arr) {
        ways = (ways + solve(currentSum - num, dp)) % MOD; // Try all elements
    }

    return dp[currentSum] = ways; // Memoize result
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, target;
    cin >> n >> target;

    arr.resize(n);
    for (ll &v : arr) cin >> v;

    vector<ll> dp(target + 1, -1);
    cout << solve(target, dp) << endl;
}
