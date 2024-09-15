#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        vector<ll> nArray;

        for(auto v: arr) {
            if(!nArray.empty() && nArray[nArray.size()-1] == v) continue;
            else nArray.push_back(v);
        }

        ll ans = 0;
        for(int i =1; i < nArray.size()-1; i++) {
            if(nArray[i-1] < nArray[i] && nArray[i+1] > nArray[i]) ans++;
            if(nArray[i-1] > nArray[i] && nArray[i+1] < nArray[i]) ans++;
        }

        cout << nArray.size() - ans << endl;
    }
} 