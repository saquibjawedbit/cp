#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

bool check(vector<pair<ll, ll>> &arr, ll mid) {
    ll leftK = 0, rightK= mid;
    for(int i = 0; i < arr.size(); i++) {

        if(leftK > arr[i].second || rightK < arr[i].first) return false;
        leftK = max(leftK, arr[i].first);
        rightK = min(rightK, arr[i].second);
        leftK = max(0LL, leftK-mid);
        rightK = rightK + mid;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<pair<ll,ll>> arr(n);
        for(auto &v: arr) cin >> v.first >> v.second;

        ll start = 0, end = 1e9;    
        while(end > start) {
            ll mid = start + (end - start)/2;
            if(check(arr, mid)) {
                end = mid;
            }
            else {
                start = mid + 1;
            }
        }

        cout << end << "\n";

    }
}