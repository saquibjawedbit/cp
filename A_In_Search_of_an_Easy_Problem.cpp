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
        int hard = 0;
        while(n-- > 0) {
            int s; cin >> s;
            hard = max(hard, s);
        }

        if(hard) cout << "HARD" << endl;
        else cout << "EASY" << endl;

    }
} 