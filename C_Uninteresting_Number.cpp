#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9+7;

int main() {
    ll tc=1; cin >> tc;
    for(ll t =1; t <= tc; t++) {
        string s; cin >> s;

        ll sum  = 0;
        for(auto &v: s) sum += (v-48);

        if(sum % 9 == 0) {
            cout << "YES" << endl;
            continue;
        }
        
        ll req = 9 - sum % 9;
        vector<ll> freq(10, 0);
        for(auto v: s) freq[(ll)(v-'0')]++;

        ll incSum = freq[2]*2 + freq[3]*6;
        if(req > incSum) {
            cout << "NO" << endl; 
        }
        else {
            bool ans = 0;
            for (ll i = 0; i <= freq[2]; i++) {
                for (ll j = 0; j <= freq[3]; j++) {
                    ll tempSum = sum + i * 2 + j * 6;
                    if (tempSum % 9 == 0) {
                        ans = 1;
                        break;
                    }
                }
                if (ans) break;
            }           
            if(ans) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}