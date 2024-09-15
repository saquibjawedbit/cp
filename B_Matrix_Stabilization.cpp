
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n, m; cin >> n >> m;;
        vector<vector<ll>> arr(n, vector<ll>(m));
        for(auto &a: arr) {
            for(auto &v: a) cin >> v;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ll maxi = arr[j][i];
                ll temp = 0;
                if(j+1 < n) temp = max(temp, arr[j+1][i]);
                if(j-1 >= 0) temp = max(temp, arr[j-1][i]); 
                if(i+1 < m) temp = max(temp, arr[j][i+1]); 
                if(i-1 >= 0) temp = max(temp, arr[j][i-1]);
                if(temp < maxi) arr[j][i] = temp; 
            }
        }

        for(auto a: arr) {
            for(auto v: a) cout << v << " ";
            cout << endl;
        }
    }
}