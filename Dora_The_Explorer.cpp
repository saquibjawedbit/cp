#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, d; cin >> n >> d;

    int *arr = new int[n];
    for(int i =0; i < n; i++) cin >> arr[i];

    int count = 0;
    for(int i =1; i < n; i++) {
        while(arr[i] <= arr[i-1]) {
            arr[i] += d;
            count++;
        }
    }

    cout << count << endl;
}

int main() {
    solve();
    return 0;
}