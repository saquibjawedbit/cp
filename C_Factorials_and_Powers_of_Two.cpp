#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> pre;
vector<ll> cumm;
ll best = INT_MAX;

void precompute() {
    // Precomputation here

    vector<ll> nre;
    for(ll i = 0; i <= 40; i++) nre.push_back(1LL << i);
    vector<ll> fact(17, 1);
    for(ll i = 1; i <= 16; i++) fact[i] = fact[i-1] * i;

    set<ll> st;
    for(auto v: fact) st.insert(v);
    for(auto v: nre) st.insert(v);

    copy(st.begin(), st.end(), back_inserter(pre));
    sort(pre.rbegin(), pre.rend());

    for(int i = pre.size()-1; i >= 0; i--) {
        if(i == pre.size()-1) cumm.push_back(pre[i]);
        else cumm.push_back(cumm.back() + pre[i]);
    }

    reverse(cumm.begin(), cumm.end());

}   

void solve(ll n, ll index, ll count) {
    if(n == 0) {
        best = min(best, count);
        return;
    }

    if(index >= pre.size() || n < 0) return;

    if(cumm[index] < n || count >= best) return; 

    if(n >= pre[index]) {
        solve(n - pre[index], index + 1, count + 1);
    }
    solve(n, index + 1, count);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    precompute();

    ll tc; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n; cin >> n;
        best = INT_MAX;
        solve(n, 0, 0);
        cout << best << endl;
    }
}