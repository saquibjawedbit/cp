#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll dfs(ll node, vector<vector<ll>> &adj, vector<ll> &visited, ll &ans, ll parent = 0) {
    if(visited[node]) return 0;

    if(adj[node].size() == 1) return 1;

    visited[node] = 1;

    ll totalDegree = 0;
    for(auto i : adj[node]) {
        if(!visited[i]) {
            ll dg = dfs(i, adj, visited, ans, 1);
            if(dg % 2 == 0) ans++;
            else totalDegree += dg;
        }
    }

    if(parent == 1) totalDegree++;

    return totalDegree;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1; //cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n; cin >> n;

        if(n == 1) {
            cout << -1 << endl;
            continue;
        }

        vector<vector<ll>> adj(n+1);

        for(ll i = 1; i < n; i++) {
            ll a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        if(n&1) {
            cout << -1 << endl;
            continue;
        }

        if(n == 2) {
            cout << 0 << endl;
            continue;
        }

        vector<ll> visited(n+1, 0);

        ll ans = 0;
        for(ll i = 1; i <= n; i++) {
            ll size = dfs(i, adj, visited, ans);
        }

        cout << ans << endl;

    }
}