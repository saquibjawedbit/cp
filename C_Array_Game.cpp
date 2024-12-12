#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll tc = 1; cin >> tc;
    for(ll t= 1; t <= tc; t++) {
        ll n, k; cin >> n >> k;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        if(k >= 3) {
            cout << 0 << endl;
        }
        else {
            sort(arr.begin(), arr.end());
            ll ans = arr[0];
            
            for(int i = 1; i < n; i++) ans = min(ans, abs(arr[i]-arr[i-1]));

            if(k == 1) {
                cout << ans << endl;
                continue;
            }
            else {
                for(int i = 0; i < n; i++) {
                    for(int j = i+1; j < n; j++) {
                        ll diff = abs(arr[i]-arr[j]);
                        int index = lower_bound(arr.begin(), arr.end(), diff) - arr.begin();
                        if(index == n) {
                            ans = min(ans, abs(diff - arr[index-1]));
                        }
                        else {
                            ans = min(ans, abs(diff - arr[index]));
                            if(index != 0) ans = min(ans, abs(diff - arr[index-1]));
                        }
                    }
                }
                cout << ans << endl;
            }

        }

    }
}