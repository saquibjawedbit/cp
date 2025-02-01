#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9+7;

ll solve(vector<ll> &arr, ll currentSum, ll target, vector<ll> &mp) {
    if(currentSum > target) {
        return 0;
    }

    if(currentSum == target) {
        mp[currentSum] = 1ll;
        return 1ll;
    }

    if(mp[currentSum] != -1) {
        return mp[currentSum];
    }

    ll ans = 0;
    for(auto v: arr) {
        ans = (ans % MOD + solve(arr, currentSum + v, target, mp) % MOD) % MOD;
    }

    mp[currentSum] = ans;

    return ans;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1; //cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n; cin >> n;
        ll target; cin >> target;

        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;
        vector<ll> mp(target+1, -1);
        ll ans = solve(arr, 0, target, mp);
        cout << ans << endl;
    }
}