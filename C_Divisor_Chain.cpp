#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t-- > 0) {
        int n; cin >> n;
        vector<int> ans;
        for(int i = 0; i <= 31; i++) {
            if( __builtin_popcount(n) == 1) break;
            if((n & (1 << i)) != 0) {
                ans.push_back(n);
                n -= (1 << i);
            }
        }
        ans.push_back(n);
        while(n != 1) {
            int div = n/2;
            n -= div;
            ans.push_back(n);
        }
        cout << ans.size() << endl;
        for(auto v: ans) cout << v << " ";
        cout << endl;
    }
}