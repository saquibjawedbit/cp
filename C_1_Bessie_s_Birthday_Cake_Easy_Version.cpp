#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n, x, y; cin >> n >> x >> y;
    int *arr = new int[x];

    for(int i = 0; i < x; i++) cin  >> arr[i];

    sort(arr, arr+x);
    int triangle = 0;

    for(int i = 1; i < x; i++) {
        if(arr[i] - arr[i-1] == 2) triangle++;
    }

    if(abs(arr[0] - arr[x-1]) == n-2) triangle++;


    cout << (x-2) + triangle << endl;
}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();
}