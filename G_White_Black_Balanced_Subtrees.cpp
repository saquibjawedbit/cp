#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll solve(vector<vector<ll>> &arr, string &s, ll index, ll &ans) {
    if(index >= arr.size()) return 0;

    ll score = (s[index-1] == 'W')? 1 : -1;
    for(auto v: arr[index]) {
        score += solve(arr, s, v, ans);
    }

    if(score == 0) ans++;

    return score;
}

int main() {
    int tc = 1; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n-1);
        for(auto &v: arr) cin >> v;
        string s; cin >> s;

        vector<vector<ll>> adjList(n+1);
        for(int i = 0; i < n-1; i++) {
            adjList[arr[i]].push_back(i+2);
        }

        ll ans = 0;
        solve(adjList, s, 1, ans);

        cout << ans << endl;
    }
}