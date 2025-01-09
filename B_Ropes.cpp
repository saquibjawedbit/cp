#include <bits/stdc++.h>


using namespace std;

#define ll long long
#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);  // Disable sync with C I/O
    cin.tie(nullptr); 
    cout.tie(nullptr);
    ll tc = 1;
    for(ll t = 1; t <= tc; t++) {
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        auto check = [&](double mid) {
            ll cnt = 0;
            for(auto &v: arr) {
                cnt += (ll)(v / mid);
                if(cnt >= k) return true;
            }
            return cnt >= k;
        };

        double left = 0, right = 1e9;
        double ans = 0;
        while(right >= left) {
            double mid = left + (right - left) / 2.0;

            if(check(mid)) {
                ans = mid;
                left = mid + 0.0000001;
            } else {
                right = mid - 0.0000001;
            }
        } 


        cout << fixed << setprecision(6) << ans << endl;
       
    }
}