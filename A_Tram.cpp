#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    //cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        int n; cin >> n;
        int people = 0, ans = 0;
        while(n-- > 0) {
            int l, e; cin >> l >> e;
            people -= l;
            people += e;
            ans = max(ans, people);
        }
        cout << ans << endl;
    }
} 