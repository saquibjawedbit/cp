#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        vector<ll> arr(3);
        for(auto &v: arr) cin >> v;
        ll minDis = INT_MAX;
        ll ans = 0;
        
        for(int i = 1; i <= 10; i++) {
            ll temp = 0;
            for(auto v: arr) temp += abs(v-i);
            if(temp < minDis) {
                minDis = temp;
            }
        }
    
        cout << minDis << endl;
    }
}