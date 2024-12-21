#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        string s; cin >> s;

        string ans = "";

        for(auto v: s) {
            if(v == 'p') ans.push_back('q');
            else if(v == 'q') ans.push_back('p');
            else ans.push_back('w');
        }

        reverse(ans.begin(), ans.end());

        cout << ans << endl;
    }
}