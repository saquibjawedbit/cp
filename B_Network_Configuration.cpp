#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tc = 1; //cin >> tc;
    for(int t =1; t <= tc; t++) {
        ll n, k; cin >> n >> k;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        sort(arr.begin(), arr.end(), greater<ll>());

        cout << arr[k-1] << endl;
        
 
    }
}

