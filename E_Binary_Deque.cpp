#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

ll query(vector<ll> &arr, ll left, ll right, ll sum) {
    ll s = arr[right] - (left == 0 ? 0 : arr[left-1]);
    return s;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n, s; cin >> n >> s;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        for(int i = 1; i < n; i++) {
            arr[i] += arr[i-1];
        }

        if(arr[arr.size()-1] < s) {
            cout << -1 << endl;
            continue;
        }


        ll ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            ll left = i, right = n-1;
            ll pos = -1;
            while(right >= left) {
                ll mid = (right + left) >> 1;
                if(query(arr, i , mid, s) <= s) {
                    pos = mid;
                    left = mid + 1;
                }
                else {
                    right = mid -1;
                }
            }
            if(pos != -1 && query(arr,i, pos, s) == s) ans = min(ans, n - (pos - i+1));
        }
        cout << ans << endl;
    }
} 
