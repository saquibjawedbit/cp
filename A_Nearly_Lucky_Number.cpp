#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    //cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        string s; cin >> s;
        ll cntr = 0;

        for(auto &v: s) {
            if(v == '4' || v == '7') cntr++;
        }

        bool ans = 1;
        s = to_string(cntr);
        for(auto &v: s) {
            if(v != '4' && v != '7') {
                ans = 0;
                break;
            }
        }

        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
} 