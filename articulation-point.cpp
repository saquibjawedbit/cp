#include <bits/stdc++.h>

using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<bool> &isVisited, unordered_map<int, vector<int>> &adjList, vector<int>& ans) {
    isVisited[node] = 1;
    disc[node] = low[node] = timer++;
    int child = 0;

    for(auto nbr: adjList[node]) {
        if(parent == nbr) continue;

        if(!isVisited[nbr]) {
            dfs(nbr, node, timer, disc, low, isVisited, adjList, ans);
            low[node] = min(low[node], low[nbr]);
            if(parent != -1 && low[node] < low[nbr]) {
                ans.push_back(node);
            }
            child++;
        }
        else {
            low[node] = min(low[node], disc[nbr]);
        }
    }

    if(parent == -1 && child > 1) {
        ans.push_back(node);
    }
}

int main() {
    int v = 6;
    vector<vector<int>> edges = {
        {1, 0},
        {0, 4},
        {1, 4},
        {2, 3},
        {3, 4},
    };
    unordered_map<int, vector<int>> adjList;

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> isVisited(v, 0);
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;
    int timer = 0;
    vector<int> ans;

    for(int i = 0; i < v; i++) {
        if(!isVisited[i]) {
            dfs(i, -1, timer, disc, low, isVisited, adjList, ans);
        }
    }

    for(auto v: ans) cout << v << " ";
    cout << endl;

}