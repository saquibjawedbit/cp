#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tc = 1; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;
        ll sum = 0;
        map<ll,bool> mp;
        bool ans = false;
        for(int i = 0; i < n; i++) {
            sum += (i&1) ? arr[i] : (-arr[i]);
            
            if(sum  == 0 || mp[sum]) {
                ans = true;
                break;
            }
            
            mp[sum] =1;
        }


        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}