#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve(vector<ll> &arr, ll index, vector<pair<ll, ll>> &ans, vector<ll> &isVisited) {
    
    for(int i = 0; i < arr.size(); i++) {
        if(isVisited[i]) continue;
        if(arr[index-1] == arr[i]) continue;
        
        isVisited[i] = 1;
        ans.push_back({index, i+1});
        solve(arr, i+1, ans, isVisited);
    }

}

int main() {
    ll tc = 1; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        vector<pair<ll, ll>> ans;
        vector<ll> isVisited(n+1, 0);
        isVisited[0] = 1;
        solve(arr, 1, ans, isVisited);

        if(ans.size() == (n-1)) {
            cout << "YES" << endl;
            for(auto &v: ans) {
                cout << v.first << " " << v.second << endl;
            }
        }
        else {
            cout << "NO" << endl;
        }
        
    }
}