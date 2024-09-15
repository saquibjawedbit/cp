#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        string a; cin >> a;
        string b; cin >> b;

        ll ans = a.size()+b.size();
        ll x = 0;
        for(int i = 0; i < b.size(); i++) {
            ll ptr = i, temp = 0;
            for(int j = 0; j < a.size(); j++) {
                if(b[ptr] == a[j]) {
                    ptr++;
                    temp++;
                }
            }
            x = max(x, temp);
        }
        ans -= x;
        cout << ans << endl;
        
    }
}