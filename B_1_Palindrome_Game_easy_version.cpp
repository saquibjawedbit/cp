#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tc= 1;
    cin >> tc;
    for(int t =1; t <= tc; t++) {
        ll n; cin >> n;
        string s; cin >> s;
        
        ll count = 0;
        for(auto &v: s) if(v == '0') count++;

        if(count == 1) {
            cout << "BOB" << endl;
            continue;
        }

        if(count&1) {
            cout << "ALICE" << endl;
        } else {
            cout << "BOB" << endl;
        }
    } 

}