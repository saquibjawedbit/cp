#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n, m; cin >> n >> m;
        vector<pair<ll,ll>> arr(n);
        for(auto& v: arr) cin >> v.second;

        for(auto& v: arr) {
            for(int i = 0; i <= 9; i++) {
                ll div = pow(10, i);
                if(v.second % div == 0) {
                    v.first = i;
                }
                else {
                    break;
                }
            }
        }

        sort(arr.begin(), arr.end(), greater<pair<ll,ll>>());


        ll ans = -1;
        bool turn = 1;
        for(auto v: arr) {
            ll length = to_string(v.second).length();
            if(turn) ans += (length - v.first);
            else ans += length;
            turn = !turn;
        }
        if(ans >= m) cout << "Sasha" << "\n";
        else cout << "Anna" << "\n";
    }
}