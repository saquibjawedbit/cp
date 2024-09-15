#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define MOD 1000000007

// 5 4 3 2 1
// 1 1 1 1 1

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++) {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (auto &v : arr) cin >> v;

        if(is_sorted(arr.begin(), arr.end())) {
            cout << 0 << endl;
            continue;
        }

        int y = arr[n - 2], z = arr[n - 1];
        if ((arr[n - 1] < arr[n - 2] ) || (y - z > y)) {
            cout << -1 << endl;
            continue;
        }
        else {            
            ll delta = arr[n - 2] - arr[n - 1]; 
            cout << n - 2 << endl;
            for (int i = 0; i < n - 2; i++) {
                arr[i] = delta;
                cout << i + 1 << " " << (int)arr.size() - 1 << " " << arr.size() << endl;
            }
            
        }
    }
}
