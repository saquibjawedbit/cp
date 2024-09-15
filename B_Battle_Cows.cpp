#include <iostream>
#include <vector>

using namespace std;

int getWin(int *arr, int n, int k) {
    int win = 0;
    int winner = 0;
    for(int i = 1; i < n; i++) {
        if(arr[winner] < arr[i]) winner = i;
        if(winner == k) win++;  
    }

    return win;
}

void solve() {
    int n, k; cin >> n >> k;
    int *arr = new int[n];
    int maxIndex = 0;

    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < n; i++) {
        if(arr[k-1] < arr[i]) {
            maxIndex = i;
            break;
        }
    }

    swap(arr[k-1], arr[0]);
    int ans = getWin(arr, n, 0);
    swap(arr[k-1], arr[0]);
    ans = max(ans, getWin(arr, n, k-1));
    swap(arr[k-1], arr[maxIndex]);
    if(maxIndex < k-1) ans = max(ans, getWin(arr, n, maxIndex));
    
    std::cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();
}