#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n, c, d; cin >> n >> c >> d;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        arr.push_back(0);
        sort(arr.begin(), arr.end());


        ll ans = d + n * c;
        ll curr = 0;
        ll index = 1;

        for(int i = 1; i <= n; i++) {
            
            while(i <= n && arr[i] < index) {
                curr += c;
                i++;
            }

            if(i <= n && arr[i] > index) {
                // cout << ans << endl;
                ll delta = arr[i] - arr[i-1]-1;
                curr += d * delta;
                ans = min(ans, curr + (n-i+1) * c);

                index = arr[i];
            }

            if(i <= n && arr[i] == index) {
                index++;
                ans = min(ans, curr + (n-i) * c);

            }
        }

        ans = min(ans, curr);
        cout << ans << endl;
    }
}