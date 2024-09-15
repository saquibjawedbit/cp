#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

ll solve(vector<ll> &a, vector<ll> &b, vector<ll> &c, ll index, vector<ll> &isVisited, vector<map<vector<ll>, ll>> &dp) {
    if(index >= a.size()) return 0;


    if(dp[index].find(isVisited) != dp[index].end()) return dp[index][isVisited];

    ll incl_a = 0, incl_b = 0, incl_c = 0;
    ll excl = 0;

    if(!isVisited[0]) {
        isVisited[0] = 1;
        incl_a = solve(a, b, c, index+1, isVisited, dp) + a[index];
        isVisited[0] = 0;
    }
    if(!isVisited[1]) {
        isVisited[1] = 1;
        incl_b = solve(a, b, c, index+1, isVisited, dp) + b[index];
        isVisited[1] = 0;
    }
    if(!isVisited[2]) {
        isVisited[2] = 1;
        incl_c = solve(a, b, c, index+1, isVisited, dp) + c[index];
        isVisited[2] = 0;
    }

    //exclude
    excl = solve(a, b, c, index+1, isVisited, dp);

    ll ans =  max(incl_a, max(incl_b, max(incl_c, excl)));
    dp[index][isVisited] = ans;

    return ans;

}



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        int n; cin >> n;
        vector<ll> a(n), b(n), c(n);
        for(auto &v: a) cin >> v;
        for(auto &v: b) cin >> v;
        for(auto &v: c) cin >> v;

        vector<ll> isVisited(3, 0);
        vector<map<vector<ll>, ll>> dp(n+1);

        ll ans = solve(a, b, c, 0, isVisited, dp);

        cout << ans << endl;

    }
} 