#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);

        for(auto &v: arr) cin >> v;
        vector<ll> mex(n);

        ll minMex = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[arr.size()-i-1] == minMex) {
                minMex++;
            }
            mex[arr.size()-i-1] = minMex;
        }

        ll mini = INT_MAX;
        ll ans = 1;
        for(int i = 0; i < arr.size()-1; i++) {
            if(mex[i+1] <= mini) {
                ans = arr.size();
            }
            mini = min(mini, mex[i]);
        }

        cout << ans << endl;
    }

}