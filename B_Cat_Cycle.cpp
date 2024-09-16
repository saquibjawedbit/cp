#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tc = 1; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        ll n, k; cin >> n >> k;

        ll a = n-1, b = 0;
        if(!(n&1)) {
            cout << (b + k-1) % n + 1 << endl;
            continue;
        } 
        else {
            ll mid = (a + b) >> 1;
            k = k % ((mid+2) * n);
            for(int i = 1; i <= k; i+=mid) {
                if((k - i) < mid) {
                    k -= i;
                    break;
                }
                b = b + mid + 1;
                b = b % n;
            }
            b = (b + k) % n;
            cout << b+1 << endl;
        }
    }
}