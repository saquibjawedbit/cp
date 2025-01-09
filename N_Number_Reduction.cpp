#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        string s; cin >> s;
        ll k; cin >> k;

        if(k >= s.size()) {
            cout << 0 << endl;
            continue;
        }

        int st = 0;
        for(int i = 0; i <= k; i++) {
            if(s[i] != '0' && s[i] < s[st]) {
                st = i;
            }
        }

        k -= st;

        string ans = "";
        ans.push_back(s[st]);

        for(int i = st+1; i < s.size(); i++) {
            while(k > 0 && ans.size() > 1 && ans.back() > s[i]) {
                ans.pop_back();
                k--;
            }

            ans.push_back(s[i]);
        }

        while(k-- > 0) ans.pop_back();

        cout << ans << endl;
    }
}