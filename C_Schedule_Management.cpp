#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool check(map<ll, ll> arr, ll x) {
    ll extra = 0;
    for(auto v: arr) {
        if(v.second >= x) extra += (v.second - x) * 2;
        else extra += ((v.second-x)&1) ? (v.second-x+1) : (v.second-x);
    }
    if(extra <= 0) return true;

    return false;
}

int main() {
    ll tc = 1; cin >> tc;
    for(ll t=1; t <= tc; t++) {
        ll n, m; cin >> n >> m;
        map<ll, ll> arr;

        for(ll i = 0; i < m; i++) {
            ll a; cin >> a;
            arr[a]++;
        }

        for(int i = 1; i <= n; i++) arr[i] = arr[i];



        ll left = 0, right = 1e6;
        ll ans = INT_MAX;
        while(right >= left) {
            ll mid = left + (right - left)/2;
            if(check(arr, mid)) {
                ans = mid;
                right = mid - 1;
            }   
            else {
                left = mid + 1;
            }
        }
        
        cout << ans << endl;
    }
}