#include <bits/stdc++.h>

using namespace std;

template <typename T>
class graph {
    public:
    unordered_map<T, list<T>> arr;

    void addEdge(int u, int v, int p) {
        arr[u].push_back(v);
        if(p == 0) arr[v].push_back(u);
    }

    void printGraph() {
        for(auto i: arr) {
            cout << i.first << " -> ";
            for(auto j: i.second) cout << j << " , ";
            cout << endl;
        }
    }
};

int main() {
    int n; cin >> n;
    graph<int> g;
    for(int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    g.printGraph();
}