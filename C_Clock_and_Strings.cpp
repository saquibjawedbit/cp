#include <iostream>

using namespace std;

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int arr[13];

    for(int i = 1; i <= 12; i++) arr[i] = 0;

    for(int i = min(a, b); i <= max(a, b); i++) arr[i] = 1;

    // for(int i = 1; i <= 12; i++) {
    //     cout << i << " " << arr[i] << endl;
    // }

    if(arr[c] == arr[d]) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();
}