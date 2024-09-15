#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool check(vector<ll> &arr, ll mid, ll k) {
    ll req = 0;
    for(ll i = 0; i < arr.size(); i++) {
        ll diff =  (mid - arr[i]);
        if(diff >= 0) req += diff;
    }
    return (req <= k);
}

ll getK(vector<ll> &arr, ll k) {
    ll req = 0;
    for(ll i = 0; i < arr.size(); i++) {
        ll diff =  (k - arr[i]);
        if(diff >= 0) req += diff;
    }
    return req;
}

int main() {
    ll tc = 1; cin >> tc;
    for(ll t =1 ; t <= tc; t++) {
        ll n, k; cin >> n >> k;
        vector<ll> arr(n);
        for(ll i = 0; i < n; i++) cin >> arr[i];

        ll start = 0, end = 1e12;
        while(end > start) {
            ll mid = end + (start - end)/2;
            if(check(arr, mid, k)) {
                start = mid;
            }
            else {
                end = mid - 1;
            }
        }
        
        ll ans = start * n - (n-1);
        ll val =  getK(arr, start);
        k -= val;
        ans += k;

        for(ll i = 0; i < n; i++) {
            if(arr[i] > start) ans++;
        }

        cout << ans << endl;


    }
}