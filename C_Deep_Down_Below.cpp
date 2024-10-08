#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

bool check(vector<vector<ll>> &arr, map<ll, vector<ll>> &maxP, ll x) {
    for(auto v: maxP) {
        for(auto y: v.second) {
            ll cnt = 0;
            for(auto z: arr[y]) {
                if(z >= (x + cnt++)) {
                    return false;
                }
            }
            x += cnt;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<vector<ll>> arr(n);
        for(auto &v: arr) {
            ll k; cin >> k;
            for(int i = 0; i <  k; i++) {
                ll el; cin >> el;
                v.push_back(el);
            }
        }

        map<ll,vector<ll>> maxP;
        for(int i = 0; i < arr.size(); i++) {
            ll cnt = 0, val = INT_MIN;
            for(auto v: arr[i]) {
                val = max(val, v - cnt + 1);
                cnt++;
            }
            maxP[val].push_back(i); 
        }
  

        ll ans = INT_MAX;
        ll left = 1, right = INT_MAX;
        while(right >= left) {
            ll mid = (right + left) >> 1ll;
            if(check(arr,maxP, mid)) {
                ans = min(ans, mid);
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        cout << ans << endl;
        
    }
} 
