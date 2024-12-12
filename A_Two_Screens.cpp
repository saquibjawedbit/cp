#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t1 = 1; t1 <= tc; t1++) {
        string s, t; cin >> s >> t;
        ll ans = 0;
        ans = s.length() + t.length();


        ll index = 0;
        bool isPresent = 0;
        while(index < s.length() && index < t.length() && s[index] == t[index]) {
            index++;
            ans--;
            isPresent = 1;
        }


        ans += isPresent;

        cout << ans << endl;

    }
} 