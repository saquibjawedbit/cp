#include <bits/stdc++.h>

using namespace std;

#define ll long long



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        ll h, n; cin >> h >> n;
        vector<ll> a(n), c(n);
        for(ll i = 0; i < n; i++) cin >> a[i];
        for(ll i = 0; i < n; i++) cin >> c[i];

        set<pair<ll ,int>> s;
        for(int i = 0; i < n; i++) {
            s.insert({1, i});
        }

        ll x = 0;
        while(h > 0) {
            auto [turn, i] = *s.begin();
            s.erase(s.begin());
            h -= a[i];
            x = turn;
            s.insert({c[i] + turn, i});
        }
        cout << x << endl;

    }
}