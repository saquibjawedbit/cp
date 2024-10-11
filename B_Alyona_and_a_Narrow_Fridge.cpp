#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

bool check(vector<ll> arr, ll mid, ll k) {
    sort(arr.begin(), arr.begin()+mid+1);


    if(arr[0] > k || arr[mid] > k) return false;

    ll h = 0;
    for(ll i = mid; i >= 0; i -= 2) {
        h += arr[i];
    } 

    // cout << mid << " " << h << endl;

   // if(mid % 2 == 0 && arr[mid] + h > k) return false;

    if(h <= k) return true;
    else return false; 
    
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    //cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n, k; cin >> n >> k;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        ll left = 0, right = arr.size()-1;
        ll ans = -1;
        while(right >= left) {
            ll mid = (left + right) >> 1;
            if(check(arr, mid, k)) {
                left = mid + 1;
                ans = mid;
            }
            else {
                right = mid - 1;
            }
        }


        cout << (ans +1) << endl;
    }
} 
