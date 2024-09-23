#include <bits/stdc++.h>

using namespace std;

#define ll long long int


int main() {
    int tc= 1;
    cin >> tc;
    for(int t =1; t <= tc; t++) {
        ll n, k; cin >> n >> k;

        ll leafs = (n * (n+1))/2;
        ll val  = n-k;
        ll ans = (val * (val + 1LL))/2LL;
        ll nAns = leafs - ans;

       if(nAns%2 == 1) cout << "NO" << endl;
       else cout << "YES" << endl;

    } 

}