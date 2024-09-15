#include <iostream>

using namespace std;

void solve() {
    int x, y; cin >> x >> y;
    if(x < y) cout << x << " " << y << endl;
    else cout << y << " " << x << endl;
}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();
}