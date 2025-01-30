#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9+7;

ll solve(vector<ll> &arr, ll currentSum, ll target, map<ll, ll>  &mp) {
    if(currentSum > target) {
        mp[currentSum] = 0;
        return 0;
    }

    if(currentSum == target) {
        mp[currentSum] = 1ll;
        return 1ll;
    }

    if(mp.find(currentSum) != mp.end()) {
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

        map<ll, ll> mp;

        ll ans = solve(arr, 0, target, mp);
        cout << ans ;
    }
}