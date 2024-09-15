#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int count = 0;
    // if(n == 1) {
    //     cout << "NO" << endl;
    //     return;
    // }
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            count++;
        }
    }
    if(count != 2) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main() {
    solve();
    return 0;
}