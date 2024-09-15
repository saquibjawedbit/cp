#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) cin >> arr[i];

    //Storing nearest city
    vector<int> frw(n, 0), back(n, 0);
    int cost = 1;
    frw[0] = 0;
    for(int i = 1; i < n-1; i++) {
        int fc = arr[i+1] - arr[i];
        int bc = arr[i] - arr[i-1];

        frw[i] = cost;

        if(fc > bc) cost += fc;
        else cost++;
    }
    frw[n-1] = cost;

    back[n-1] = 0; cost = 1;
    for(int i = n-2; i >= 1; i--) {
        int fc = (arr[i+1] - arr[i]);
        int bc = (arr[i] - arr[i-1]);
        back[i] = cost;
        cost += bc > fc ? bc : 1;
    }
    back[0] = cost;

    int q; cin >> q;
    while(q-- > 0) {
        int a, b; cin >> a >> b;
        a--; b--;
        //Going to destination
        int ans = 0;
        if(b > a) ans = (frw[b] - frw[a]);
        else ans = (back[b] - back[a]);
        cout << ans << endl;
    }
}

int main() {
    int t;; cin >> t;
    while(t-- > 0) solve();
}