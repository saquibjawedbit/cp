#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        int a, b, n; cin >> a >> b >> n;
        
        int mini = min(a, b);
        int maxi = max(a, b);
        int ans = 0;

        while(mini <= n && maxi <= n) {
            //cout << mini << " " << maxi << endl;
            mini += maxi;
            ans++;
            if(mini > maxi) swap(mini, maxi);
        }

        cout << ans << endl;

        

    }
} 