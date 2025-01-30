#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll a1, a2, a4, a5; cin >> a1 >> a2 >> a4 >> a5;

        ll ans = 0;
        for(int a3 = -500; a3 <= 500; a3++) {
            ll nAns = 0;
            if(a1+a2 == a3) nAns++;
            if(a2+a3 == a4) nAns++;
            if(a3+a4 == a5) nAns++;


            ans = max(ans, nAns);

        }
        cout << ans << endl;
    }
}