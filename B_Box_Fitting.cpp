#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n, w; cin >> n >> w;
        multiset<ll> st;
        for(int i = 0; i < n; i++) {
            ll val; cin >> val;
            st.insert(val);
        }

        ll ans = 1, wLeft = w;
        while(!st.empty()) {
            auto val = st.upper_bound(wLeft);
            if(val != st.begin()) {
                val--;
                wLeft -= *(val);
                st.erase(val); 
            }
            else {
                wLeft = w;
                ans++;
            }
        }

        cout << ans << endl;
        
    }
} 
