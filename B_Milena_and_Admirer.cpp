#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;
        ll ans = 0, mini = arr[arr.size()-1];
        for(ll i = arr.size()-2; i >= 0; i--) {
            if(mini < arr[i]) {
                ll sa = (arr[i] + mini - 1) / mini;
                ans += sa - 1;
                mini = arr[i] / sa;
            }
            else mini = arr[i];
        }
        cout << ans << endl;
    }
}