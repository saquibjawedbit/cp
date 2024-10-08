#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        int n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        ll ans1 = 0, ans2 = 0;
        ll cntr1 = 0, cntr2 = 0;
        for(int i = 0; i < n; i+=2) {
            ans1 = max(arr[i], ans1);
            cntr1++;    
        }
        for(int i = 1; i < n; i+=2) {
            ans2 = max(arr[i], ans2);
            cntr2++;
        }

        ans1 += cntr1; ans2 += cntr2;
        cout << max(ans1, ans2) << endl;      
    }
} 