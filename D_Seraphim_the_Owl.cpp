#include <iostream>

#define ll long long

using namespace std;

void solve() {
    ll n, m; cin >> n >> m;
    ll *a = new ll[n];
    ll *b = new ll[n];

    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];

    ll cost = 0;
    if(n < m) return;
    for(ll i = n-1; i >= 0; i--) {
        if(i < m) break;
        cost += min(a[i], b[i]);
    }

    ll minCost = INT_MAX;
    ll ccost = 0;
    for(ll i = m-1; i > 0; i--) {
        minCost = min(minCost, a[i] + ccost);
        ccost += b[i];
    }

    minCost = min(minCost,  a[0] + ccost);
    cost += minCost;
    cout << cost << endl;
}

int main() {
    ll t; cin >> t;
    while(t-- > 0) solve();
}