#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;
void solve() {
    int n; cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr +n);

    int maxScore = 0;
    unordered_map<int, int> map;
    for(int i = 0; i < n; i++) {
        if(arr[i] == maxScore) {
            maxScore++;
        }
        map[arr[i]]++;
    }

    int score = maxScore;
    bool secondTime = false;
    for(int i = 0; i < maxScore; i++) {
        if(map[i] <= 1 && secondTime) {
            score = i;
            break;
        }
        if(map[i] <= 1 && !secondTime) secondTime = true;
    }

    cout << score << endl;
}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();

    return 0;
}