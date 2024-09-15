#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;

    int *arr = new int[n];
    for(int i =0; i < n; i++) cin >> arr[i];

    int k = 0;
    //sort(arr, arr+n);

    for(int i =1 ; i < n; i++) {
        int d = abs(arr[i] - arr[i-1]);
        k = max(d, k);
    }

    cout << k << endl;
}

int main() {
    solve();
    return 0;
}