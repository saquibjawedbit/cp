#include <iostream>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;

    int i = 0, j = 0, k= 0;
    int ans = 0;

    while(i < n && j < m) {
        if(a[i] == b[j]) {
            k++; i++;
        }
        j++;
    }
    ans = max(ans, k);
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();

    return 0;
}