#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n; cin >> n;
        vector<ll> arr(n), brr(n);

        for(auto &v: arr) cin >> v;
        for(auto &v: brr) cin >> v;

        set<ll> st;
        for(auto a: arr) {
            for(auto b: brr) {
                st.insert(a + b);
            }
        }

       
        if(st.size() >= 3) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}