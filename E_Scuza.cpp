#include <bits/stdc++.h>

using namespace std;

#define ll long long

using namespace std;

ll solve(vector<pair<ll, ll>> &arr, ll h) {
    ll l = 0, r = arr.size()-1;
    ll ans = 0;
    while(r >= l) {
        ll mid = l + (r - l)/2;
        if(arr[mid].first == h) {
            return arr[mid].second;
        }
        else if(arr[mid].first < h) {
            l = mid+1;
            ans = arr[mid].second;
        }
        else {
            r = mid -1;
        }
    }

    return ans;
}

int main() {
    int tc = 1; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        ll n, q; cin >> n >> q;
        vector<ll> h(n), leg(q);
        for(auto &v: h) cin >> v;
        for(auto &v: leg) cin >> v;

        vector<pair<ll, ll>> arr;
        ll sum = 0, maxi = INT_MIN;
        for(auto v: h) {
            sum += v;
            maxi = max(maxi, v);
            pair<ll, ll> temp = {maxi, sum};
            if(!arr.empty() && arr[arr.size()-1].first == maxi) {
                arr[arr.size()-1].second = sum;
                continue;
            }
            arr.push_back(temp);
        }
        

        for(auto v: leg) {
            ll ans = solve(arr, v);
            cout << ans << " "; 
        }   cout << endl;


    }
}