#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        int n, q; cin >> n >> q;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;
        vector<ll> query(q);
        for(auto &v: query) cin >> v;
        
        map<ll, ll> mp;
        for(ll index = 0; index < n; index++) {
            ll left = index+1;
            ll right = n-index;
            ll total = left * right -1;
            mp[total]++;
            if(index+1 != n && arr[index]+1 != arr[index+1ll]) {
                total = (index+1ll) * (n-index-1ll);
                //cout << (index+1) << " " << (n-index-1) << endl;
                mp[total] += (arr[index+1] - arr[index]-1);
            }
            
        }

        for(auto &val: query) {
            cout << mp[val] << " ";
        } cout << endl;
    }
} 