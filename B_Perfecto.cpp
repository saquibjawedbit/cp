#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool isPerfectSquare(ll n) {
    ll x = sqrt(n);
    return x * x == n;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n; cin >> n;
        
        ll total = (n * (n+1)) / 2.0;

        if (isPerfectSquare(total)) {
            cout << -1 << endl;
            continue;
        }

        vector<ll> ans;
        ll sum = 0;
        for(int i  = 1; i <= n; i++) ans.push_back(i);

        for(int i = 0; i < n; i++) {
            sum += ans[i];
            if (isPerfectSquare(sum)) {
                sum -= ans[i];
                swap(ans[i], ans[i+1]);
                sum += ans[i];
                
            }
        }

        for(int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << endl;
    }
}