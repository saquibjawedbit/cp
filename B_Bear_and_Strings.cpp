#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    string s; cin >> s;
    

    ll ans = 0;
    ll prev = 0;
    ll n = s.size();
    for(int i = 0; i < n-3; i++) {
        if(s.substr(i, 4) == "bear") {
            ans += (i - prev + 1) * (n-i-3);
            prev = i+1;
        }
    }

    cout << ans << endl;

    return 0;
}