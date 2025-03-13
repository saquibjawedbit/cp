#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n, x; cin >> n >> x;
        vector<ll> a(n);
        for(auto &v: a) cin >> v;
        ll sum = 0;
        for(auto v: a) sum += v;
        double avg = (1.0 * sum)/n;

        // cout << n << " " << avg << endl;


        if(avg == x) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}