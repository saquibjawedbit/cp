#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(n), b(m);

    for (auto &v : a) cin >> v;
    for (auto &v : b) cin >> v;

    ll sum1 = 0, sum2 = 0;
    
    // Calculate sum1 and sum2
    for (auto v : b) sum1 += v;
    for (auto v : a) sum2 += v;

    // Create a map to store occurrences of a[i] * sum2
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i] * sum2]++;
    }

    // Create a map to store occurrences of b[i] * sum1
    for (int i = 0; i < m; i++) {
        mp[b[i] * sum1]++;
    }

    // Calculate total sum of the grid beauty
    ll totalSum = 0;
    for (auto v : a) {
        totalSum += (sum1 * v);
    }

    while (q-- > 0) {
        ll x; 
        cin >> x;

        ll req = totalSum - x; // This is the difference we need to check

        bool ans = false;
        // Check if we can form the required difference using the map
        for (auto v : mp) {
            ll nReq = req - v.first;
            
            if ((nReq == v.first && mp[nReq] > 1) || (nReq != v.first && mp[nReq] > 0)) {
                ans = true;
                break;
            }
        }

        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
