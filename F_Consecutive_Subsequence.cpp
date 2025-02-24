#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //ll tc; cin >> tc;
    ll tc = 1;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n; cin >> n;
        vector<ll> a(n);
        for(auto &v: a) cin >> v;

        map<ll, ll> mp;
        ll ans = 0, curr = 0;
        for(ll i = 0; i < n; i++) {
            mp[a[i]] = max(mp[a[i]], mp[a[i] - 1] + 1);
            if(mp[a[i]] > ans) {
                ans = mp[a[i]];
                curr = a[i];
            }
        }

        cout << ans << endl;
        vector<ll> nb;
        for(int i = a.size()-1; i >= 0; i--) {
            if(a[i] == curr && curr >= 0) {
                nb.push_back(i+1);
                curr--;
            }
        }

        reverse(nb.begin(), nb.end());

        for(auto v: nb) cout << v << " ";
        cout << endl;
    }
}