#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

ll check(vector<ll> &pre, ll mid, ll i) {
    ll cost = pre[i] + (mid-1) * (i+1);
    return cost;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n, x; cin >> n >> x;
        vector<ll> arr(n);
        for(auto &v: arr)  cin >> v;
        
        sort(arr.begin(), arr.end());
        for(int i = 1; i < arr.size(); i++) {
            arr[i] += arr[i-1];
        }
        ll ans = 0;

        for(int i = 0; i < n; i++) {
            ll cntr = -1;
            ll left = 0, right = 1e9;
            while(right >= left) {
                ll mid = (right + left) >> 1;
                if(check(arr, mid, i) <= x) {
                    cntr = mid;
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            //cout << cntr << endl;
            if(cntr != -1) ans += cntr;
        }

        
        cout << ans << endl;
    }

} 
