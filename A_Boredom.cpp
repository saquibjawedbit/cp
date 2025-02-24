#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //ll tc; //cin >> tc;
    ll tc = 1;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n; cin >> n;
        vector<ll> arr(n);

        vector<ll> freq(100005, 0);
        for(auto &i: arr) {
            cin >> i;
            freq[i]++;
        }

        vector<ll> dp(100005, 0);

        dp[1] = freq[1];

        ll ans = 0;
        for(int i = 2; i < 100005; i++) {
            dp[i] = max(freq[i] * i + dp[i-2], dp[i-1]);
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;

    }
}