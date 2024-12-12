#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t=1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        map<ll, ll> mp;
        for(auto &v: arr) {
            ll temp = v % 100;
            if(temp % 5 == 0) {
                if(temp % 10 != 0) mp[v+5]++;
                else mp[v]++;
            }   
            else if(temp == 0) {
                mp[v]++;
            }
            else {
                v = temp;
                while(v <= 118) {
                    if(v % 10 == 0) break;
                    v = (v + (v % 10));
                }
                mp[v]++;
            }
        }

        if(mp.size() == 1) cout << "Yes" << endl;
        else cout << "No" << endl;

    }
}