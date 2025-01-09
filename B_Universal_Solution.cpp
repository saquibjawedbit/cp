#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        string s1; cin >> s1;
  
        ll r = 0, s = 0, p =0;
        for(auto v: s1) {
            if(v == 'R') r++;
            else if(v == 'S') s++;
            else p++;
        }

        char ch = ' ';
        if(r >= s && r >= p) ch = 'P';
        else if(s >= r && s >= p) ch = 'R';
        else ch = 'S';

        for(int i = 0; i < s1.size(); i++) cout << ch;

        cout << endl;
    }
}