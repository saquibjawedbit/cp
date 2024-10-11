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

        bool inc = (arr[0] < arr[1]);
        vector<ll> ans;
        ans.push_back(arr[0]);
        for(int i = 1; i < n; i++) {
            bool is_inc = arr[i] >= arr[i-1];
            if(is_inc != inc) {
                ans.push_back(arr[i-1]);
                inc = !inc;
            }
        }
        ans.push_back(arr[n-1]);
        cout << ans.size() << endl;
        for(auto v: ans) {
            cout << v << " ";
        } cout << endl;
    }
} 
