#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n,m; cin >> n >> m;
        vector<ll> arr(n+1);
        for(int i = 1; i <= n; i++) {
            arr[i]  = i;
        }


        while(m-- > 0) {
            ll a, d, k; cin >> a >> d >> k;
            while(k-- > 0) {
                arr[a + d * k] = arr[a];
            }
        }

        ll ans = 0;
        
        if(arr[i] == )

        
    }
} 