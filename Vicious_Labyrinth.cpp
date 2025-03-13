#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n, k; cin >> n >> k;
        vector<ll> arr;
        for(int i = 1; i <= n; i++) arr.push_back(i);

        for(int i = 0; i < arr.size(); i++) {
            if(k%2 == 1) {
                if(arr[i] == n) {
                    arr[i] = n-1;
                }
                else {
                    arr[i] = n;
                }
            }
            else {
                if(arr[i] == n-1) {
                    arr[i] = n;
                }
                else {
                    arr[i] = n-1;
                }
            }
        }

        for(auto v: arr) cout << v << " ";
        cout << endl;
        
    }
}