#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tc  =1; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        vector<ll> next(n, -1);
        ll nextElement = n-1;
        for(int i = n-1; i >= 0; i--) {
            if(arr[nextElement] != arr[i]) {
                next[i] = nextElement+1;
            } 
            else if(i != n-1) {
                next[i] = next[i+1];
            }

            nextElement = i;
        }

        // for(auto &v : next) {
        //     cout << v << " ";
        // } cout << endl;


        ll q; cin >> q;
        while(q -- > 0) {
            ll l, r; cin >> l >> r;
            ll left = next[l-1];
            ll right = next[r-1];
            if(left <= r && left != -1) {
                cout << l << " " << left << endl;
            }
            else {
                cout << -1 << " " << -1 << endl;
            }
        }
        cout << endl;

    }
}