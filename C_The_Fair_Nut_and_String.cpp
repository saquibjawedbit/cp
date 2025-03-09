#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1; //cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        string s; cin >> s;

        vector<ll> arr;
        arr.push_back(0);
        for(auto v: s) {
            if(v == 'a') {
                arr.back() += 1;
            }
            else if(v == 'b' && !arr.empty() && arr.back() != 0) {
                arr.push_back(0);
            }
        }

        ll ans = 1;
        for(ll i = 0; i < arr.size(); i++) {
            ans = ((ans % MOD) * ((arr[i]+1) % MOD)) % MOD;
        }

        ans = (ans % MOD - 1 % MOD) % MOD;
        cout << ans << endl;
    }
}