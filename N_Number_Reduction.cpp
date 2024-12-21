#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        string s; cin >> s;
        ll k; cin >> k;
        
        map<char, vector<ll>> mp;
    
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]].push_back(i);
        }

        map<ll, bool> isvisited;

        for(auto &[ch, arr]: mp) {
            for(auto v: arr) {
                if(k <= 0) break;
                while(v+1 < s.size() && isvisited[v]) v++;
                if(v+1 < s.size() && s[v+1] == '0' && s[v] != '0') continue;

                isvisited[v] = 1;
                k--;
            }

            if(k <= 0) break;
        }

        string ans = "";
        ll st = 0;
        for(auto &[index, _] : isvisited) {
            ans += s.substr(st, index+1);
            st = index+2;
        }

        cout << ans << endl;

    }
}