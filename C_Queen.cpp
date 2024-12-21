#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(map<ll, vector<pair<ll, ll>>> &adjList, ll parent, ll c, vector<ll> &ans) {
    
    ll cnt = 0;
    for(auto v: adjList[parent]) {
        if(v.second == 1) cnt++;
        solve(adjList, v.first, v.second, ans);
    }

    if(cnt == adjList[parent].size() && c == 1) {
        ans.push_back(parent);
    }
}

int main() {
    ll n; cin >> n;
    
    map<ll, vector<pair<ll, ll>>> adjList;
    for(int i = 0; i < n; i++) {
        ll p, c; cin >> p >> c;
        adjList[p].push_back({i+1, c});
    }

    vector<ll> ans;
    solve(adjList, -1, 0, ans);

    sort(ans.begin(), ans.end());

    if(ans.empty()) {
        cout << -1 << endl;
        return 0;
    }

    for(auto &v: ans) cout << v << " ";
    cout << endl;
}