#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;


// Calculate (base^exponent) % mod efficiently
ll pow_mod(ll base, ll exponent, ll mod) {
    ll result = 1;
    base %= mod;
    
    while (exponent > 0) {
        // If exponent is odd, multiply result with base
        if (exponent & 1)
            result = (result * base) % mod;
        
        // Exponent = exponent / 2
        exponent >>= 1;
        
        // Base = base^2
        base = (base * base) % mod;
    }
    
    return result;
}


class DSU {
private:
    vector<ll> parent, rank;
    
public:
    // Initialize DSU with n elements
    DSU(ll n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        
        // Each element is initially its own parent
        for(ll i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    // Find the representative (root) of the set containing x (with path compression)
    ll find(ll x) {
        if (x < 0 || x >= parent.size()) {
            return -1;  // Element not present in DSU
        }

        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }


    // Union by rank: attach smaller rank tree under root of higher rank tree
    void unite(ll x, ll y) {
        ll root_x = find(x);
        ll root_y = find(y);
        
        if(root_x == root_y) return;
        
        if(rank[root_x] < rank[root_y]) {
            parent[root_x] = root_y;
        } else if(rank[root_x] > rank[root_y]) {
            parent[root_y] = root_x;
        } else {
            parent[root_y] = root_x;
            rank[root_x]++;
        }
    }
    
    // Check if x and y are in the same set
    bool same(ll x, ll y) {
        return find(x) == find(y);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1; //cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n, k; cin >> n >> k;
        set<ll> st;

        DSU dsu(n);
    
        for(int i = 0; i < n - 1; i++) {
            ll u, v, w; cin >> u >> v >> w;
            if(w == 0) {
                dsu.unite(u, v);
                st.insert(u);
                st.insert(v);
            }
        }

        map<ll, ll> mp;
        for(int i = 1; i <= n; i++) {
            mp[dsu.find(i)]++;
        }

        ll del = 0;
        for(auto i : mp) {
            del = (del % MOD +  pow_mod(i.second, k, 1000000007) % MOD) % MOD;
        }
        

        ll total = ((pow_mod(n, k, MOD) - del) % MOD + MOD) % MOD;


        cout << total << endl;
    }
}