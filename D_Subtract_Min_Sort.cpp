#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;
        bool ans = true;
        for(int i = 0; i < arr.size()-1; i++) {
            arr[i+1] -= arr[i];
            if(arr[i+1] < 0) {
                ans = false;
                break;
            }
            arr[i] = 0;
        }

        if(!ans) {
            cout << "NO" << endl;
            continue;
        }

        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] < arr[i-1]) {
                ans = false;
                break;
            }
        }


        cout << (ans ? "YES" : "NO") << endl;
    }
}