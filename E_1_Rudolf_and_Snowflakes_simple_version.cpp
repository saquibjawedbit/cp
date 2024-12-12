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
        bool ans = false;
        for(int i = 2; i <= sqrt(n); i++) {
            for(int p = 1; p <= 20; p++) {
                ll v =  (pow(i, p)-1)/(i-1);
                //cout << i << " " << p << " " << v << " " << n << endl;
                if(v == n) {
                    //cout << i << " " << p << " " << v << " " << n << endl;
                    ans = 1;
                    break;
                }
                if(v > n) break;
            }
            if(ans) break;
        } 

        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }
} 
