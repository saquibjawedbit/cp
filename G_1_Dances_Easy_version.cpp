#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tc = 1; cin >> tc;
    for (ll t1 = 1; t1 <= tc; t1++) {
        ll n, m; cin >> n >> m;
        vector<ll> a(n, 1), b(n);
        for(int i = 1; i < n; i++) cin >> a[i];
        for(auto &v: b) cin >> v;

        sort(a.begin(), a.end()); sort(b.begin(), b.end());

        ll up = 0, down = 0;
        ll ans = 0;

        while(up < n && down < n) {
            if(a[up] < b[down]) {
                up++;
                down++;
            }
            else if(a[up] >= b[down]) {
                down++;
                ans++;
            }
        }

        cout << ans << endl;
        
    }
}