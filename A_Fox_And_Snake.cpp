#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    // cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n, m; cin >> n >> m;
        bool right = 0;
        vector<vector<char>> arr(n, vector<char>(m, '.'));
        for(ll i = 0; i < n; i++) {
            if((i&1) == 0) {
                for(ll j = 0; j < m; j++) arr[i][j] = '#';
                right = !right;
            }
            else {
                if(right) arr[i][m-1] = '#';
                else arr[i][0] = '#';
            }
        }

        for(auto &ans: arr) {
            for(auto &v: ans) cout << v;
            cout << endl;
        }
    }
} 