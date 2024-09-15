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
        vector<ll> arr(n, 0);
        for(auto &v: arr) cin >> v;

        int maxi = 0, mini = 0;
        for(int i = 0; i < n; i++) {
            if(arr[maxi] < arr[i]) maxi = i;

            if(arr[mini] >= arr[i]) mini = i;
        }
        //cout << maxi << endl;
        ll ans = maxi  + n - mini  - 1;

        if(maxi > mini) ans--;
        cout << ans << endl; 



    }
} 