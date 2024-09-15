#include <bits/stdc++.h>

#define ll long long
 
using namespace std;

void solve() {
    int m; cin >> m;
    map<ll, ll> mp, val;
    mp[0] = 1;
    for(ll i = 1; i < 31; i++) mp[i] = mp[i-1] * 2;


    while(m-- > 0) { // O(m)
        int q, v; cin >> q >> v;
        if(q == 1) {
            val[v]++;
        }
        else {
            
            for(int i = 30; i >= 0; i--) {
                ll s = v/mp[i];
                int n = min(s, val[i]);
                v -= (mp[i] * n);
            }

            if(v == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}
 
int main() {
    solve();
}