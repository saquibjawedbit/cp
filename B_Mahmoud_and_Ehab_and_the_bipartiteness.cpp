#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

void solve(map<ll, vector<ll>> &adjList, ll r, ll &s1, ll &s2, bool val, ll p) {
    if(val) s1++;
    else s2++;


    for(auto v: adjList[r]) {
        if(p == v) continue;
        solve(adjList, v, s1, s2, !val, r);
    }

}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        map<ll, vector<ll>> adjList;
    
        for(int i = 1; i < n; i++) {
            ll u, v; cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        ll s1 = 0, s2 = 0;

        solve(adjList, 1, s1, s2, 0, 0);
       

        //cout << s1 << " " << s2 << endl;


        ll ans = (s1 * s2) - (n-1);
        cout << ans << endl;
        
    }
} 

