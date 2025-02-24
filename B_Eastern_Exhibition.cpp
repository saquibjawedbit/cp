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
        ll n; cin >> n;
        vector<ll> a;
        vector<ll> b;

        for(int i = 0; i < n; i++) {
            ll na, nb; cin >> na >> nb;
            a.push_back(na);
            b.push_back(nb);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        ll aC = 1;
        if(a.size() % 2 == 0) {
            aC = a[a.size() / 2] - a[a.size() / 2 - 1] + 1;
        
        }
        ll bC = 1;
        if(b.size() % 2 == 0) {
            bC = b[b.size() / 2] - b[b.size() / 2 - 1] + 1;
        }
        

        ll ans = aC * bC;  
        cout << ans << endl;
    }
}