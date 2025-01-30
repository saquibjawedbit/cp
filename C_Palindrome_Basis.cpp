#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9+7;

bool isPalindromic(ll n) {
    string s = to_string(n);
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

ll solve(vector<ll> &st, ll currentSum, ll target, map<vector<ll>, ll>& dp, ll lastUsed) {
    if(target < currentSum) return 0;
    
    if(target == currentSum) {
        if(dp.find(st) != dp.end()) {
            return 0;
        }
        dp[st] = 1;
        return 1;
    }
    
    ll ans = 0;
    for(int i = lastUsed; i <= (target - currentSum); i++) {
        if(isPalindromic(i)) {
            st.push_back(i);
            ans = (ans % MOD + solve(st, currentSum + i, target, dp, i) % MOD) % MOD; // Pass i as lastUsed
            st.pop_back();
        }
    }
    
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n; cin >> n;
        map<vector<ll>, ll> dp;
        vector<ll> st;
        ll ans = solve(st, 0, n, dp, 1) % MOD;

        cout << ans << endl;
    }
}