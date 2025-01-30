#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n, m; cin >> n >> m;
        vector<vector<ll>> arr(n, vector<ll>(m));

        for(auto &v: arr) {
            for(auto &e: v) {
                cin >> e;
            }
        }

        map<ll, ll> mp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mp[arr[i][j]] = i;
            }
        }

        vector<ll> ans;
        set<ll> cows;
        ll index = 0;
        for(auto &[card, cow]: mp) {
            if(cows.find(cow) == cows.end()) {
                ans.push_back(cow+1);
                cows.insert(cow);
            }
            else {
                if(cows.size() != n) {
                    ans.clear();
                    ans.push_back(-1);
                    break;
                }

                if(ans[index] == cow+1) {
                    index = (index + 1) % n;
                }
                else {
                    ans.clear();
                    ans.push_back(-1);
                    break;
                }
            }
        }

        for(auto &v: ans) cout << v << " ";
        cout << endl;

    }
}