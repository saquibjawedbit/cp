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
        ll size = n * (n-1)/2;
        vector<ll> arr(size);
        for(auto &v: arr) cin >> v;

        sort(arr.begin(), arr.end());

        vector<ll> ans;
        ll val = INT_MAX, cntr = 1;
        for(int i = 0; i < arr.size(); i++) {
            val = min(arr[i], val);
            if((cntr) % (n-1) == 0) {
                ans.push_back(val);
                val = INT_MAX;
                n--;
                cntr = 0;
            }
            cntr++;
        }
        ans.push_back(ans[ans.size()-1]);
        for(auto v: ans) cout << v << " ";
        cout << endl;
    }
} 