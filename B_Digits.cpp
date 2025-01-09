#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tc = 1; cin >> tc;

    for(ll t = 1; t <= tc; t++) {
        ll n, d; cin >> n >> d;

        
        map<ll, bool> ans;
        for(ll i = 1; i <= 9; i+=2) {
            if(d % i == 0) ans[i] = 1;
        }

        if(n >= 9) {
            ans[3] = 1;
            if((n-1) % 6 == 0) ans[7] = 1;
            ans[9] = 1;
        }
        else {
            ll res = 1;
            for(int i = 1; i <= n; i++) {
                res *= i;
            }
            
            if(res % 3 == 0) ans[3] = 1;
            if(res % 6 == 0) ans[7] = 1;
            if(res % 9 == 0) ans[9] = 1;
        }



        for(auto v: ans) cout << v.first << " ";
        cout << endl;       
    }
}