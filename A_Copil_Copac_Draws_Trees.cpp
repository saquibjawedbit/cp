#include <bits/stdc++.h>
using namespace std;

#define ll long long

void dfs(vector<vector<pair<ll, ll>>> &adjList, ll currentNode, ll parent, ll currentIndex, vector<ll> &levels) {
    for(auto v : adjList[currentNode]) {
        if(v.first == parent) continue;
        levels[v.first] = levels[currentNode] + (v.second < currentIndex ? 1 : 0);
        dfs(adjList, v.first, currentNode, v.second, levels);
    }
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        ll n;
        cin >> n;

        vector<vector<pair<ll, ll>>> adjList(n + 1);
        for (int i = 0; i < n - 1; i++) {
            ll u, v;
            cin >> u >> v;
            adjList[u].push_back({v, i});
            adjList[v].push_back({u, i});
        }

        vector<ll> levels(n + 1, 0);  // Track reading levels for each node
        levels[1] = 1;  // Start level for node 1

        dfs(adjList, 1, -1, -1, levels);

        cout << *max_element(levels.begin() + 1, levels.begin() + n + 1) << endl;
    }

    return 0;
}
