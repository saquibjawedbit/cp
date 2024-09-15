#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    //cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n, q; cin >> n >> q;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        ll sum  = 0;
        for(auto v: arr) sum += v;

        bool first = true;
        unordered_map<ll, ll> mp;
        ll element;
        while(q-- > 0) {
            ll m; cin >> m;
            if(m == 1) {
                ll i, v; cin >> i >> v;
                if(first) {
                    sum -= arr[i-1];
                    arr[i-1] = v;
                    sum += arr[i-1];
                }
                else {
                    if(mp.find(i-1) != mp.end()) {
                        sum -= mp[i-1];
                    }
                    else {
                        sum -= element;
                    }
                    sum += v;
                    mp[i-1] = v;
                }
            }   
            else {
                ll v; cin >> v;
                sum = v * n;
                element = v;
                mp.clear();
                first = false;
            }
            cout << sum << endl;
        }
        
    }
} 
