#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n,x, m; cin >> n >> x >> m;

        ll lm = x, ul = x;
        while(m-- > 0) {
            ll left, right; cin >> left >> right;
            if(lm >= left && ul <= right) {
                lm = left;
                ul = right;
            }
            else if(ul >= left && ul <= right) {
                ul = right;
            }
            else if(lm >= left && lm <= right) {
                lm = left;
            }
            
            //cout << lm << " " << ul << endl;
        }
        ll ans = ul - lm + 1;
        cout << ans << endl;        
    }
} 
