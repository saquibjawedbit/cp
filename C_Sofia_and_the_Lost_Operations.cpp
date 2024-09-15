#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 0; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        int n; cin >> n;
        vector<ll> a(n, 0);
        vector<ll> b(n, 0);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        int m; cin >> m;
        vector<ll> d(m, 0);
        for(int i = 0; i < m; i++) cin >> d[i];
        map<ll, ll> mp, isVisited;
        for(int i = 0; i < m; i++) mp[d[i]]++;

        bool ans = true;
    
        for(int i = 0; i < n; i++) {
            if(a[i] != b[i]) {
                if(mp[b[i]] == 0) {
                    ans = false;
                    break;
                }
                else {
                    mp[b[i]]--;
                    isVisited[b[i]]++;
                }
            }
            else {
                isVisited[a[i]]++;
            }
        }
        // if(n >= m) {
        //     for(auto v: mp) {
        //         if(v.second != 0 && isVisited[v.first] == 0) {
        //             ans = false;
        //             break;
        //         } 
        //     }
        // }    



        if(!ans) cout << "NO" << endl;
        else cout << "YES" << endl;


    }
}