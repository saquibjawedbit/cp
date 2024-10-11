#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n, k; cin >> n >> k;

        if(k >= n) {
            cout << 1 << endl;
            continue;
        }

        ll ans = INT_MAX;
        for(ll i = sqrt(n); i >= 1; --i) {
            if(n % i == 0) {
               ll maxi = max(i, n/i);
               ll mini = min(i, n/i);
               if(maxi <= k) {
                    ans = min(ans,n/maxi);
               }
               else if(mini <= k) {
                    ans = min(ans,n/mini);
               }
            }
        }

        cout << ans << endl;
        
        
    }
} 
