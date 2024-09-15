#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
       ll x1, y1; cin >> x1 >> y1;
       ll x2, y2; cin >> x2 >> y2;

       if((x1 > y1 && x2 > y2) || (y1 > x1 && y2 > x2)) {
        cout << "YES" << endl;
       } 
       else {
        cout << "NO" << endl;
       }
    }
}