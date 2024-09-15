#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    int ans = y/x;
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();
    return 0;
}