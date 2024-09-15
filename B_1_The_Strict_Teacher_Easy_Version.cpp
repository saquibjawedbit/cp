#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    int tc= 1;
    cin >> tc;
    for(int t =1; t <= tc; t++) {
        ll n, m, q; cin >> n >> m >> q;
        vector<ll> arr(m);
        vector<ll> nArray(q);

        for(auto &v: arr) cin >> v;

        sort(arr.begin(), arr.end());

        while(q-- > 0) {
            ll val; cin >> val;
            if(nArray[0] < arr[0]) {
                cout << arr[0]-1 << endl;
            }
            else if(nArray[0] > arr[1]) {
                cout << n - arr[1] << endl;
            } else {
                ll mid = (arr[0] + arr[1])/2;
                cout << mid - arr[0] << endl;
            }
        }

    } 

}