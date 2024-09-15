#include <bits/stdc++.h>

using namespace std;



int main() {
    int t = 1;
    while(t-- > 0) {
        int n; cin >> n;
        vector<int> arr(n, 0);
        for(int i = 0; i < n; i++) cin >> arr[i];

        bool ans = 0;
        for(int i = 0; i <= (1 << n) -1; i++) {
            int sum = 0;
            for(int j = 0; j < n; j++) {
                bool bit = i & (1 << j);
                if(bit) {
                    sum += arr[j];
                }
                else {
                    sum -= arr[j];
                }
                sum %= 360;
            }
            //cout << sum << endl;
            if(sum % 360 == 0) {
                ans = true;
                break;
            }
        }

        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}