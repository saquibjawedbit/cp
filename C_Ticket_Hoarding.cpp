#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tc = 1; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];

        sort(arr.begin(), arr.end());

        ll ans = 0, x = 0;
        for(int i = 0; i < n; i++) {
            if(k >= m) {
                ans += (arr[i]+x) * m;
                k -= m;
                x += m;
            }
            else {
                ans += (arr[i]+x) * k;
                break;
            }
        }
        cout << ans << endl;
    }    
}