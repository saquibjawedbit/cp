#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1; //cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n, q; cin >> n >> q;
        vector<ll> a(n);
        for(auto &v: a) cin >> v;

        vector<ll> diff(n+2, 0);

        while(q-- > 0) {
            ll l, r; cin >> l >> r;
            diff[l-1]++; diff[r]--;
        }

        vector<ll> pre;
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            sum += diff[i];
            pre.push_back(sum);
        }

        sort(a.begin(), a.end(), greater<ll>());
        sort(pre.begin(), pre.end(), greater<ll>());


        ll ans = 0;
        for(int i = 0; i < n; i++) {
            ans += a[i] * pre[i];
        }
        cout << ans << endl;
                
    }
}