#include <bits/stdc++.h>

using namespace std;


#define ll long long


class DSU {
    vector<int> parent, size;

public:
    // Initialize DSU with `n` elements
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1); // Initially, each set has size 1
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Each element is its own parent
        }
    }

   
    // Find operation with path compression
    int find(int x) {
        // Ensure the element is valid
        if (x < 0 || x >= parent.size()) {
            // cerr << "Index out of bounds: " << x << endl;
            return -1; // or handle the error appropriately
        }

        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union operation by size
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }
    }

    // Get the size of the set containing element x
    int getSize(int x) {
        int root = find(x);
        return size[root];
    }

    // Get the super parent (root parent) of a node
    int getSuperParent(int x) {
        return find(x); // Alias for `find` function
    }
};



int main() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> arr(m);

    for(auto &v: arr) {
        ll s; cin >> s;
        while(s-- > 0) {
            ll a; cin >> a;
            v.push_back(a);
        }
    }

   DSU *dsu = new DSU(n+1);

    for(auto v: arr) {
        for(int i = 1; i < v.size(); i++) {
            dsu->unite(v[0], v[i]);
        }
    }


    for(int i = 1; i <= n; i++) {
        cout << max(dsu-> getSize(dsu->getSuperParent(i)), 1) << " ";
    } cout << endl;


}