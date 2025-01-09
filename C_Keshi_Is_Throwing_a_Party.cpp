#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);  // Disable sync with C I/O
    cin.tie(nullptr); 
    cout.tie(nullptr);
    ll tc = 1;
    cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n;
        cin >> n;
        vector<pair<ll,ll>> arr(n);
        
        for(int i = 0; i < n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }

        

        auto check = [&](ll val) {
            ll cnt = 0;
            for(int i = 0; i < n; i++) {
                if(arr[i].second >= cnt && arr[i].first >= (val-cnt-1)) {
                    cnt++;
                }
            }
            return cnt >= val;
        };

        ll ans =1;
        ll left = 0, right = n;
        while(right >= left) {
            ll mid = left + (right - left) / 2;
            if(check(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        cout << ans << endl;
       
    }
}