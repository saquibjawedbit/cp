#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<string> arr(n);
        for(auto& v: arr) {
            cin >> v;
        }

        ll ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < (n-i-1); j++) {
                ll cntr = 0;
                if(arr[i][j] == '1') cntr++;
                if(arr[j][n-i-1] == '1') cntr++;
                if(arr[n-i-1][n-j-1] == '1') cntr++;
                if(arr[n-j-1][i] == '1') cntr++;
                //cout << cntr << endl;
                ans += min(4 - cntr, cntr);
            }
        }
        
        cout << ans << endl;
    }
} 
