#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> cost(n), amnt(n);
        for(auto &v: cost) cin >> v;
        for(auto &v: amnt) cin >> v;

        vector<ll> diff;
        for(int i = 0; i < n; i++) {
            ll ct = amnt[i] - cost[i];
            diff.push_back(ct);
        }

        sort(diff.begin(), diff.end());

        ll ans = 0;
        ll left = 0, right = n-1;
        while(right > left) {
            if((diff[right] + diff[left]) >= 0) {
                ans++;
                left++;
                right--;
            }
            else {
                left++;
            }
        }

        cout << ans << endl;
        
    }
} 
