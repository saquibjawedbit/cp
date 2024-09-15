#include <iostream>

using namespace std;

int gcd(int x, int y) {
    if(y == 0) return x;

    return gcd(y, x % y);
}   

void solve() {
    int x; cin >> x;
    int y = 1, ans = INT_MIN;
    for(int i = 1; i < x; i++) {
        int r = gcd(x, i)+i;
        if(r >= ans) {
            ans = r;
            y = i;
        }
    }

    cout << y << endl;
}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();
}