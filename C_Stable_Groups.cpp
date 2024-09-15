#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tc =1;
    //cin << tc;
    for(int t =1; t <= tc; t++) {
        ll n, k, x; cin >> n >> k >> x;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        ll ans = 0;
        sort(arr.begin(), arr.end());
        vector<ll> differ;
        for(int i = 1; i < n;  i++) {
            ll diff = arr[i] - arr[i-1];
            ll nc = (diff -1)/x;
            if(nc > 0) differ.push_back(nc);
        }
        sort(differ.begin(), differ.end(), greater<ll>());
        
        while(!differ.empty()) {
            ll val = differ[differ.size()-1];
            if(val <= k) {
                differ.pop_back();
                k -= val;
            }
            else {
                break;
            }
        }

        cout << differ.size()+1 << endl;
    }
}