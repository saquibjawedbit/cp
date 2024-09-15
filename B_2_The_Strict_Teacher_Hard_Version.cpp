#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll upperBound(vector<ll>& arr, ll target) {
    int left = 0;
    int right = arr.size();
    
    while (left < right) {
        ll mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

ll lowerBound(vector<ll>& arr, ll target) {
    int left = 0;
    int right = arr.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}


int main() {
    int tc= 1;
    cin >> tc;
    for(int t =1; t <= tc; t++) {
        ll n, m, q; cin >> n >> m >> q;
        vector<ll> arr(m);
        for(auto &v: arr) cin >> v;

        sort(arr.begin(), arr.end());

        while(q-- > 0) {
            ll val; cin >> val;
            if(val < arr[0]) {
                cout << arr[0]-1 << endl;
            }
            else if(val > arr[m-1]) {
                cout << n - arr[m-1] << endl;
            } else {
                ll lower = lowerBound(arr, val);
                ll upper = upperBound(arr, val);

                //cout << arr[lower-1] << " " << arr[upper] << endl;
                
                ll mid = (arr[lower-1] + arr[upper]) /2;
                //cout << mid << endl;
                cout << mid - arr[lower-1] << endl;
            }
        }

    } 

}