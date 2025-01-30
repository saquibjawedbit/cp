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
        ll n; cin >> n;
        string s; cin >> s;
        vector<ll> arr(2, 0);

        for(auto v: s) {
            if(v == '+') arr[1]++;
            else arr[0]++;
        }

        ll q; cin >> q;
        while(q-- > 0) {
            ll x, y; cin >> x >> y;
            ll k = (arr[1] - arr[0]) * y;
            ll delta = x - y;
            if(delta == 0) {
                if(arr[0] == arr[1]) cout << "YES" << endl;
                else cout << "NO" << endl;
                continue;
            }

            ll nk = -k/delta;

            //cout << nk << endl;

            if((nk >= -arr[0] && nk <= arr[1] && k % delta == 0)) cout << "YES" << endl;
            else cout << "NO" << endl;

        }

    }
}