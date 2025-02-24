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
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        vector<ll> pre(n+1, 0);
        for(ll i = 1; i <= n; i++) {
            pre[i] = pre[i-1] ^ arr[i-1];
        }

        if(pre[n] == 0) {
            cout << "YES\n";
            continue;
        }

        bool flag = false;
        for(ll i = 1; i < n; i++) {
            for(ll j = i+1; j < n; j++) {
                if(pre[i] == (pre[j] ^ pre[i]) && pre[i] == (pre[n] ^ pre[j])) {
                    flag = true;
                    break;
                }
            }
        }

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}