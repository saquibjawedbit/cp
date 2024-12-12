#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9+7;

int main() {
    ll tc=1; cin >> tc;
    for(ll t =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        ll sum = 0;
        for(auto v: arr) sum += v;
        ll target = sum / n;

        if(sum % n != 0) {
            cout << "NO" << endl;
            continue;
        }

        
        for(ll i = 1; i < n-1; i++) {
            if(arr[i-1] == target) continue;

            if(arr[i-1] < target) {
                arr[i+1] -= (target - arr[i-1]);
            }
            else {
                arr[i+1] += (arr[i-1] - target);
            }

            // cout << nextVal << endl;
        }

        if(arr[arr.size()-1] == target) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}