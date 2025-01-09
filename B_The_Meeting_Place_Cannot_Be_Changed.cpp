#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);  // Disable sync with C I/O
    cin.tie(nullptr); 
    cout.tie(nullptr);
    ll tc = 1;
    // cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n;
        cin >> n;
        vector<ll> x(n), v(n);

        for(auto &v: x) cin >> v;
        for(auto &v: v) cin >> v;

        auto check = [&](long double mid) {
            long double time = 0;
            for(int i = 0; i < x.size(); i++) {
                time = max(time, (long double)abs(x[i] - mid) / v[i]);
            }

            return time;
        };
  
        long double left = 0, right = 1e9, epsilon = 1e-7;
        long double ans = 0;
        while((right-left) > epsilon) {
            long double mid = left + (right - left) / 2;

            if(check(mid) <= check(mid + epsilon)) {
                right = mid;
            }
            else { 
                left = mid;
            }
        }

        cout << fixed << setprecision(6) << check((left+right)/2) << endl;
       
    }
}