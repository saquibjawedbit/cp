#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    // cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        ll ans = 0;
        while(n--  > 0) {
            string s; cin >> s;
            if(s[0] == 'I') ans += 20;
            else if(s[0] == 'D') ans += 12;
            else if(s[0] == 'O') ans += 8;
            else if(s[0] ==  'C') ans += 6;
            else ans += 4;
        }
        cout << ans << endl;
    }
} 