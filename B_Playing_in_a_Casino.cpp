
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n, m; cin >> n >> m;
        vector<vector<ll>> arr(m, vector<ll>(n));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> arr[j][i];
            }
        }
        ll ans = 0;
        vector<ll> prefixSum(n);
        for(auto& v: arr) {
            sort(v.begin(), v.end());
            ll sum = 0;
            for(int j = n-1; j >= 0; j--) {
                sum += v[j];
                prefixSum[j] = sum;
            }

            for(int j = 0; j < n-1; j++) {
                ans += abs(v[j] * (n - j - 1) - prefixSum[j+1]);
            }
        }

        cout << ans << endl;

    }
} 
