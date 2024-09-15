#include <bits/stdc++.h>

using namespace std;

#define ll long long

int fn(int b, int k) {
    return b *(b * k -1);
}

int main() {
    int tc =1; cin >> tc;
    for(int t =1; t <=tc; t++) {
        int a, b; cin >> a >> b;
        ll ans = a;
        for(ll i = 2; i <= b; i++) {
            int e = (a + i)/(i * i);
            int k = e;
            if(k >= 0) ans += k;
            else break;
        }    
        cout << ans << endl;    
    }
    return 0;
}