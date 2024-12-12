#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9+7;

int main() {
    ll tc=1; cin >> tc;
    for(ll t =1; t <= tc; t++) {
        ll n, m; cin >> n >> m;
        vector<string> arr(n);
        for(auto &v: arr) cin >> v;

        // sort(arr.begin(), arr.end(), [](string &f, string &l) {
        //     return f.size() < l.size();
        // });

        ll ans = 0;
        ll cc = 0;

        for(auto v: arr) {
            cc += v.size();

            if(cc <= m) {
                ans++;
            }
            else {
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}