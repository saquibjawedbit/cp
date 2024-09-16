#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tc =1;
    cin >> tc;
    for(int t = 1; t <= tc; t++) {
        ll n, k; cin >> n >> k;
        ll ans = 1;
        for(int i = 1; i <= k; i++) {
            ans = (ans * n) % 1000000007;
        }
        cout << ans << endl;
    }
}