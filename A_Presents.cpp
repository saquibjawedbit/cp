#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    // cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<int> arr(n);
        for(auto &v: arr) cin >> v;
        vector<int> ans(n);

        for(int i = 0; i < n; i++) ans[arr[i]-1] = i+1;

        for(auto v: ans) cout << v << " ";
        cout << endl;

    }
} 