#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    //cin >> tc;
    for(ll t  = 1; t <= tc; t++) {
        string val; cin >> val;

        for(int i = 0; i < val.length(); i++) {
            if(i == 0 && val[i] == '9') continue;
            ll digit = val[i] - 48;
            val[i] = min(digit, 9 - digit) + 48;
        }
        ll ans = stoll(val);
        cout << ans << endl;
    }
} 