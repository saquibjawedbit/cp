#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n, m; cin >> n >> m;
        vector<string> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];

        int h = 0, k = 0, maxCnt = 0;
        for(int  i = 0; i < n; i++) {
            ll cnt = 0;

            for(int j = 0; j < m; j++) {
                if(arr[i][j] == '#') {
                    if(maxCnt == 0) k = j+1;
                    cnt++;
                }
            }
            if(maxCnt < cnt) {
                maxCnt = cnt;
                h = i+1;
            }
        }

        cout << h << " " << k << endl;
       
    }
}