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
            ll extraSteps =  (k-1) / mid;
            cout << (b + k -1 + extraSteps) % n + 1 << endl;
        }
    }
}