#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tc = 1; cin >> tc;
    for(int t =1; t <= tc; t++) {
        ll n; cin >> n;
        string a, b; cin >> a >> b;
        ll zeroa = 0, zerob = 0;

        for(int i = 0; i < n; i++) {
            if(a[i] == '0') zeroa++;
            if(b[i] == '0') zerob++;
        }

        if(zeroa != zerob) {
            cout << "NO" << endl;
            continue;
        }

        bool ans = true;
        bool flip = false;
        for(int i = n-1; i >= 0; i--) {
            if((!flip && a[i] != b[i]) || (flip && a[i] == b[i])) {
                ll zero = 0, one = 0;
                while(i >= 0 && a[i] != b[i] && !flip) {
                    if(a[i] == '0') zero++;
                    else one++;
                    i--;
                }
                while(i >= 0 && a[i] == b[i] && flip) {
                    if(a[i] == '0') zero++;
                    else one++;
                    i--;
                }

                if(zero != one) {
                    ans = false;
                    break;
                }
                i = i+1;
                flip = !flip;
            }
        }

        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
 
    }
}

