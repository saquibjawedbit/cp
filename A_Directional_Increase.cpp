#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t =  1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        ll sum = 0;
        ll index = 0;
        for(auto &v: arr) {
            sum += v;
            index++;
            if(sum <= 0) {
                break;
            }
        }

        for(int i = index; i < arr.size(); i++) {
            if(arr[i] != 0) break;
            index++;
        }
        // cout << index << " " << sum << endl;
        if(sum == 0 && index == n) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}