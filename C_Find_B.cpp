#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t =1; t <= tc; t++) {
        ll n, q; cin >> n >> q;
        vector<ll> arr(n);
        vector<ll> c(n);
        for(auto& v: arr) cin >> v;

        ll prev = 0, prevSum = 0;
        for(int i = 0; i < n; i++) {
            c[i] = arr[i] + prevSum;
            prevSum = c[i];
            if(arr[i] == 1) {
                arr[i] = prev + 1; 
            }
            else {
                arr[i] = prev;
            }
        
            prev = arr[i];
        }  
    

        while(q-- > 0) {
            ll s, e; cin >> s >> e;

            if(s == e) {
                cout << "NO" << "\n";
                continue;
            }

            ll nOnes = arr[e-1];
            if(s != 1) nOnes = arr[e-1] - arr[s-2];

            ll sum = c[e-1];
            if(s != 1) sum = c[e-1] - c[s-2];




            sum -= nOnes;
            sum -= ((e-s+1) - nOnes) * 1;

            if(sum < nOnes) cout << "NO" << "\n";
            else cout << "YES" << "\n";

        }

    }
}