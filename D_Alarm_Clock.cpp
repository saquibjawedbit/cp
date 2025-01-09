#include <bits/stdc++.h>


using namespace std;

#define ll long long

int main() {

    ios_base::sync_with_stdio(false);  // Disable sync with C I/O
    cin.tie(nullptr); 
    ll tc = 1;
    // cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        if(k == 1) {
            cout << n << endl;
            continue;
        }

        sort(arr.begin(), arr.end());

        queue<ll> q;
        for(int i = 0; i < k-1; i++) {
            q.push(arr[i]);
        }

        ll ans = 0;
        for(int i = k-1; i < arr.size(); i++) {
            if(arr[i] - q.front() < m) {
                ans++;
            }
            else {
                q.pop();
                q.push(arr[i]);
            }
        }

        cout << ans << endl;
    }
}