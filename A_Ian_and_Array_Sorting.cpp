#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        if(n&1) {
            cout << "YES" << endl;
            continue;
        }

        
        //inc 
        for(int i = 1; i < n-1; i++) {
            if(arr[i-1] != arr[i]) {
                ll diff = arr[i-1] - arr[i];
                arr[i] += diff;
                arr[i+1] += diff;
            }
        }

        bool sorted = is_sorted(arr.begin(), arr.end());

        if(sorted) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}