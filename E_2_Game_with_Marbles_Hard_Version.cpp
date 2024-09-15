#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

bool compare(pair<ll,ll> &a, pair<ll, ll> &b) {
    ll diff1 = a.first + a.second;
    ll diff2 = b.first + b.second;

    return abs(diff1) > abs(diff2);


}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<pair<ll, ll>> b_a(n);
        for(auto &v: b_a) cin >> v.second;
        for(auto &v: b_a) cin >> v.first;

        sort(b_a.begin(), b_a.end(), compare);

        // for(auto v: b_a) {
        //     cout << v.second << " " << v.first << endl;
        // }

        bool alice = true;
        ll ans = 0;
        for(auto &v: b_a) {
            if(alice) {
                v.second -= 1;
                v.first = 0;
            }
            else {
                v.first -= 1;
                v.second = 0;
            }
            alice = !alice;
            ans += (v.second - v.first);
        }

        cout << ans << endl;

    }
}