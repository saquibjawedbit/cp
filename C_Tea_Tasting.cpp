#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n; cin >> n;
        vector<ll> a(n), b(n);

        for(auto &v: a) cin >> v;
        for(auto &v: b) cin >> v;

        vector<ll> prefix;
        prefix.push_back(0);

        for(auto v: b) prefix.push_back(prefix.back() + v);

        vector<ll> prefixAns(n+1, 0);
        vector<ll> ans(n+1, 0);
        for(int i = 0; i < n; i++) {
            ll index = upper_bound(prefix.begin(), prefix.end(), a[i] + prefix[i]) - prefix.begin() - 1;
            prefixAns[i]++;
            prefixAns[index]--;
            ans[index] += a[i] - (prefix[index] - prefix[i]);
        }

        for (int i = 0; i < n; ++i) {
            cout << prefixAns[i] * b[i] + ans[i] << ' ';
            prefixAns[i + 1] += prefixAns[i];   
        } cout << endl;
    }
}