#include <iostream>

using namespace std;

void solve() {
    int n; cin >> n;
    int *x = new int[n-1];
    int *a = new int[n];

    for(int i = 0; i < n-1; i++) cin >> x[i];

    int maxElement = 0;
    for(int i = 0; i < n-1; i++) maxElement = max(maxElement, x[i]);

    a[0] = x[0] + 1;
    for(int i = 1; i < n; i++) {
        a[i] = a[i-1] * (maxElement/a[i-1] + 1)  + x[i-1];
    }

    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();
}