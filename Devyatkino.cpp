#include <bits/stdc++.h>

using namespace std;

#define ll long long


bool check(ll n) {
    string s = to_string(n);
    for(auto v: s) {
        if(v == '7') return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n; cin >> n;

        string s = to_string(n);
        ll ans = INT_MAX;
        for(auto v: s) {
            if(v == '7') {
               ans = 0; break;
            }
        }


        if(ans == 0) {
            cout << 0 << endl;
            continue;
        }

        ll add = 9;
        for(int i = 0; i < s.size(); i++) {
            ll newNum = n;
            ll count = 0;

            while(!check(newNum)) {
                newNum += add;
                count++;
            }

            ans = min(ans, count);
            add = add * 10ll + 9ll;
        }
        //800001

        cout << ans << endl;


    }
}