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
        string s; cin >> s;

        ll zero = 0, one = 0;
        vector<ll> prefixXor;
        prefixXor.push_back(0);
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') zero = zero ^ arr[i];
            else one = one ^ arr[i];

            prefixXor.push_back(prefixXor.back() ^ arr[i]);
        }

        ll q; cin >> q;
        while(q-- > 0) {
            ll m; cin >> m;
            if(m == 1) {
                ll l, r; cin >> l >> r;
                zero ^= prefixXor[r] ^ prefixXor[l-1];
                one ^= prefixXor[r] ^ prefixXor[l-1];
            }
            else {
                ll nm; cin >> nm;
                if(nm == 0) cout << zero << " ";
                else cout << one << " ";
            }
        }

        cout << endl;
    }
}