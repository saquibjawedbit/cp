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
        vector<ll> arr(n);

        for(auto &v: arr) cin >> v;

        sort(arr.begin(), arr.end());
        vector<ll> ans;

        while(m-- > 0) {
            char sign; cin >> sign;
            ll l, r; cin >> l >> r;

            if(arr[arr.size()-1] >= l && arr[arr.size()-1] <= r) {
                if(sign == '+') arr[arr.size()-1]++;
                else arr[arr.size()-1]--;
            }
            

            ans.push_back(arr[arr.size()-1]);

        }

        for(auto v: ans) {
            cout << v << " ";
        }
        cout << endl;
    }
} 