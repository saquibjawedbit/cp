#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int isPossible = m/n;
    if(isPossible == 0) {
        cout << "NO" << endl;
        return;
    }
    else if(n == 1 || m % n == 0 || n&1 == 1) {
        cout << "YES" << endl;
        return;
    }
    vector<int> arr;
    isPossible += 1;
    for(int i = 0; i < n; i++) arr.push_back(isPossible);

    int sum = isPossible * n;
    int j = 0;
    while(sum > m && j < n) {
        if(arr[j] != 1) {
            arr[j]--;
            sum--;
        }
        if(sum == m) {
            sum = -1;
            break;
        }
        if(arr[j+1] != 1) {
            arr[j+1]--;
            sum--;
        }
        j+=2;
    }
    if(sum != m) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();
    return 0;
}