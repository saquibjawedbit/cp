#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct DSU {
    int n;
    vector<int> fa, sz;
    
    DSU(int n): n(n) {
        fa.resize(n + 1);
        sz.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            fa[i] = i;
            sz[i] = 1;
        }
    }
    
    int find(int x) {
        if(x == fa[x]) return fa[x];
        return fa[x] = find(fa[x]);
    }
    
    void merge(int x, int y) {
        int dx = find(x), dy = find(y);
        if(dx < dy) swap(dx, dy);
        if(dx != dy) {
            sz[dy] += sz[dx];
            fa[dx] = dy;
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n, m1, m2; cin >> n >> m1 >> m2;

        vector<vector<ll>> adj(n+1);

        DSU dsu1(n+1), dsu2(n+1);
        for(ll i = 0; i < m1; i++) {
            ll u, v; cin >> u >> v;
            adj[u].push_back(v);
            //adj[v].push_back(u);
        }

        for(ll i = 0; i < m2; i++) {
            ll u, v; cin >> u >> v;
            dsu2.merge(u, v);
        }


        ll ans = 0;
        // First Removing
        for(ll i = 1; i <= n; i++) {
            for(ll j = 0; j < adj[i].size(); j++) {
                if(dsu2.find(i) != dsu2.find(adj[i][j])) {
                    ans++;
                }
                else {
                    dsu1.merge(i, adj[i][j]);
                }
            }
        }

        // Second Adding
        for(int i = 1; i <= n; i++) {
            if(dsu1.find(i) != dsu2.find(i)) {
                dsu1.merge(i, dsu2.find(i));
                ans++;
            }
        }
        

        cout << ans << endl;
    }
    return 0;
}