#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll solve(vector<ll> &arr, ll index, vector<ll> &dp) {
    if(index > arr.size()) return 0;

    if(dp[index] != -1) return dp[index];

    ll ans = 0;
    for(int i = index; i <= arr.size(); i+=index) {
        if(arr[index-1] < arr[i-1]) ans = max(ans, solve(arr, i, dp) + 1);
  
    }

    dp[index] = ans;

    return ans;
}

int main() {
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);

        vector<ll> dp(n+2, -1);

        for(auto &v: arr) cin >> v;

        ll ans = 0;

        for(int i = 0; i < arr.size(); i++) ans = max(ans, solve(arr, i+1, dp)+1);
        cout << ans << endl;
    }
    return 0;
}