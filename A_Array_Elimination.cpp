#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        vector<ll> nArr;

        for(int i = 30; i >= 0; i--) {
            ll cnt = 0;
            for(auto v: arr) {
                ll bit = v & (1 << i);
                if(bit != 0) cnt++;
            }
            nArr.push_back(cnt);
            
        }

        cout << 1 << " ";
        for(int k = 2; k <= n; k++) {
            bool ans = true;
            for(auto cnt: nArr) {
                if(cnt%k != 0) {
                    ans = false;
                    break;
                } 
            }
            if(ans) cout << k << " "; 
        } cout << endl;
    }
} 
