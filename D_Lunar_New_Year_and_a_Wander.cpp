#include <bits/stdc++.h>

using namespace std;

#define ll long long

void dfs(vector<vector<ll>> &arr, ll node, vector<bool> &isVisited, priority_queue<int, std::vector<int>, std::greater<int>> &st) {
    if(isVisited[node]) return;

    cout << node << " ";
    isVisited[node] = 1;

    for(auto v: arr[node]) {
        if(!isVisited[v]) {
            st.push(v);
        }
    }

    while(!st.empty()) {
        ll tp = st.top();
        st.pop();
        if(!isVisited[tp]) dfs(arr, tp, isVisited, st);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1; //cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n, m; cin >> n >> m;
        vector<vector<ll>> arr(n+1);

        for(int i = 1; i <= m; i++) {
            ll a, b; cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        priority_queue<int, std::vector<int>, std::greater<int>> st;

        vector<bool> vis(n+1, 0);
        dfs(arr, 1, vis, st);
        cout << endl;
    }
}