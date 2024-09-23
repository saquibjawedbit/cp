#include <bits/stdc++.h>

using namespace std;

#define ll long long


ll check(vector<ll> &arr, double val) {
    ll cnt = 0;
    for(int i = 0; i < arr.size()-1; i++) {
        if(arr[i] < val) cnt++;
        else break;
    }

    return cnt;
}

int main() {
    int tc= 1;
    cin >> tc;
    for(int t =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        if(n <= 2) {
            cout << -1 << endl;
            continue;
        }

        sort(arr.begin(), arr.end());


        double avg = 0;
        for(auto v: arr) avg += v;
        // avg /= n;

        // ll left  = 0, right = INT_MAX;
        // ll ans = -1;
        // double half = (double)n/2;

        // while(right >= left) {
        //     ll mid = left + (right - left)/2LL;
        //     double nAvg = avg + (double)mid/n;
        //     if(check(arr, nAvg/2) > half) {
        //         right = mid - 1;
        //         ans = mid;
        //     }
        //     else {
        //         left = mid + 1;
        //     }
        // }


        // if(ans == -1) cout << -1 << endl;
        // else cout << max(ans, 0LL) << endl;

        ll ans = arr[n/2] * 2 * n - avg+1;
        cout << max(ans, 0LL) << endl;
    } 

}