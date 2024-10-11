#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    //cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n), nArr(n);

        for(auto &v: arr) cin >> v;
        for(auto &v: nArr) cin >> v;

        queue<ll> q;
        for(auto v: arr) q.push(v);
        map<ll, ll> mp;

        ll ans = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            // Element is already removed
            while(mp.find(q.front()) != mp.end()) {
                mp[q.front()]--;
                q.pop();
            }

            if(q.front() == nArr[i]) {
                q.pop();
            } 
            else {
                mp[nArr[i]]++;
                ans++;
            }
        }  
        cout << ans << endl;
    }
} 
