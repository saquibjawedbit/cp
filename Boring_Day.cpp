#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n, l, r; cin >> n >> l >> r;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        vector<ll> prefixSum;
        prefixSum.push_back(0);
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            prefixSum.push_back(sum);
        }

        ll ans = 0;
        ll left = 0, right = 0;
        while(right < prefixSum.size() && left < prefixSum.size()) {
            ll sum = prefixSum[right] - prefixSum[left];
            if(sum < l) right++;
            else if(sum > r) left++;
            else {
                ans++;
                left = right;
                right++;
            }
        }
        cout << ans << endl;
    }
}