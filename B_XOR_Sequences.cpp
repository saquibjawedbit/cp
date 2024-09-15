#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main() {
    int tc = 0; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        int x, y; cin >> x >> y;

       int a = 0;
       for(int i = 0; i < 32; i++) {
        int bit1 = (x >> i) & 1;
        int bit2 = (y >> i) & 1;
        if(bit1 != bit2) {
            a = i;
            break;
        }
       }

       int ans = pow(2, a);
       cout << ans << endl;

    }
}