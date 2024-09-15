#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    //cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        vector<ll> arr(3);
        for(auto &v: arr) cin >> v;

        sort(arr.begin(), arr.end());

        ll ans = (arr[1]-arr[0]) + (arr[2] - arr[1]);
        cout << ans << endl;

    }
} 