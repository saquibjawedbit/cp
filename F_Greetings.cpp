#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<pair<ll, ll>> arr(n);
        for(auto &v: arr) cin >> v.first >> v.second;

        sort(arr.begin(), arr.end());
        vector<ll> np;
        for(auto v: arr) np.push_back(v.second);
        sort(np.begin(), np.end());

        ll ans = 0;
        for(int i = 0; i < n; i++) {
            ll left = 0, right = np.size()-1;
            ll nt = -1;
            while(right >= left) {
                ll mid = left + (right - left)/2;
                if(arr[i].second == np[mid]) {
                    nt = mid;
                    break;
                }
                else if(arr[i].second > np[mid]) left = mid+1;
                else right = mid - 1;
            }
            if(nt != -1) ans += (nt);
            np.erase(np.begin() + nt);
        }
        cout << ans << endl;
    }
}