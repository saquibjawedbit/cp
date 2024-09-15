#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 0; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        int n, m; cin >> n >> m;
        string s; cin >> s;

        map<char, int> c;
        for(int i = 0; i < n; i++) c[s[i]]++;

        int ans = 0;

        for(int ch = 'A'; ch <= 'G'; ch++) {
            if(c[ch] < m) ans += (m-c[ch]);
        }

        cout << ans << endl;
    }
    return 0;
}