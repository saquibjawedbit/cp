#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9+7;

int main() {
    ll tc=1; cin >> tc;
    for(ll t =1; t <= tc; t++) {
        string s; cin >> s;
        

        for(int i = 0; i < s.size(); i++) {
            ll digit = s[i] - 48;
            ll maxDigit = digit, index = -1;
            for(int j = 9; j >= 1; j--) {
                if((i+j) >= s.size()) continue;
                ll cDigit = s[i+j] - '0' - j;
                
                if(cDigit > maxDigit || (cDigit == maxDigit && index != -1) ) {
                    index = i+j;
                    maxDigit = cDigit;
                }
            }

            if(index != -1) {
                for(ll j = index; j >= i; j--) {
                    s[j] = s[j-1];
                }

                s[i] = maxDigit+48;
            }

            
        }

        cout << s << endl;
    }

    return 0;
}