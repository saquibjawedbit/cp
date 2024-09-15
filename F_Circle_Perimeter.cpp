#include <iostream>
#include <cmath>

using namespace std;

long long calc(long long r) {
    long long ans = 0;
    for(long long i = 1; i < r; i++) {
        ans += (long long)sqrt(r*r - i*i-1) + 1;
    }
    ans = ans * 4;
    return ans;
}


void solve() {
    long long r,ans= 0;
    cin >> r;
    ans = calc(r+1) - calc(r);
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();
}