#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    const int MAX_BIT = 2e6;
    vector<ll> cnt(MAX_BIT, 0);
    
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        cnt[x]++;
    }
    
    ll ans = 0;
    for(int i = 0; i < MAX_BIT-1; i++) {
        cnt[i+1] += (cnt[i] >> 1ll);
        cnt[i] = (cnt[i] & 1ll);
        ans += cnt[i];
    }

    cout << ans << endl;
    
    return 0;
}