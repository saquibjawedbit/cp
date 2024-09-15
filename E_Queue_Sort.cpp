#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tc = 0; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        int n; cin >> n;
        vector<ll> arr(n, 0);
        for(int i = 0; i < n; i++) cin >> arr[i];
        int minIndex = 0;
        for(int i = 1; i < n; i++) {
            if(arr[i] < arr[minIndex]) minIndex = i;
        }
        bool isSorted = true;
        for(int i = minIndex + 1; i < n; i++) {
            if(arr[i-1] > arr[i]) {
                isSorted = false;
                break;
            }
        }

        if(isSorted) cout << minIndex << endl;
        else cout << -1 << endl;
    }
}