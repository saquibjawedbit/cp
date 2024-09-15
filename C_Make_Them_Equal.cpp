#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc =1;
    cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n; cin >> n;
        char ch; cin >> ch;
        string s; cin >> s;

        ll cnt = 0;
        for(auto v: s) if(v == ch) cnt++;

        if(cnt == n) {
            cout << 0 << endl;
            continue;
        }
        ll a = -1, b = -1;
        for(int i = n/2; i < n; i++) {
            if(s[i] == ch) {
                cnt = 1;
                a = i+1;
                break;
            }
        } 

        if(a != -1) {
            cout << cnt << endl;
            cout << a << endl;
        }
        else {
            cout << 2 << endl;
            cout << n << " " << n-1 << endl;
        }
    }
}