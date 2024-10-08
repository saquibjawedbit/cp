#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n, m; cin >> n >> m;
        vector<ll> arr(n), nArr(m);
        for(auto &v: arr) cin >> v;
        for(auto &v: nArr) cin >> v;

        sort(arr.begin(), arr.end(), greater<ll>());

        ll cost = 0, left = 0;
        for(auto v: arr) {
            if(left < m && nArr[left] < nArr[v-1]) {
                cost += nArr[left++];
            }
            else {
                cost += nArr[v-1];
            }
        }

        cout << cost << endl;


    }
} 
