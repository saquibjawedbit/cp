#include <iostream>

using namespace std;


void solve() {
    int n; cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i++) cin >> arr[i];

    int magicElement = arr[0];

    int minDig = INT_MAX;
    int dig = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == magicElement) dig++;
        else {
            minDig = min(minDig, dig);
            dig = 0;
        }
    }
    dig = 0;
    for(int i = n-1; i >= 0; i--) {
        if(arr[i] == magicElement) dig++;
        else {
            minDig = min(minDig, dig);
            dig = 0;
        }
    }

    if(minDig == INT_MAX) minDig = -1;
    cout << minDig << endl;

}

int main() {
    int t; cin >> t;
    while( t-- > 0) solve();
    return 0;
}