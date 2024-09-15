#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

ll getMin(vector<ll> &a, queue<ll> &q) {
    ll mini = LONG_LONG_MAX;
    for(ll i = 0; i< a.size(); i++) {
        mini = min(mini, abs(q.front()-a[i]));
        q.push(q.front());
        q.pop();
    }
    return mini;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);
        for(auto &v: a) cin >> v;
        for(auto &v: b) cin >> v;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        queue<ll> q;

        for(auto v: b) q.push(v);

        ll ans = LONG_LONG_MIN;
        for(int i = 0; i < n; i++) {
            ll arr = getMin(a, q);
            q.push(q.front());
            q.pop();
            ans = max(ans, arr);
        }

        cout << ans <<endl;
    }
}