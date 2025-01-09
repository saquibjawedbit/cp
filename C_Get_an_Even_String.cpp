#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        string s;
        cin >> s;
        
        ll n = s.size();
        vector<vector<ll>> mp(26);
        

        ll incl = 0, left = -1;
        for(int i = 0; i < s.size(); i++) {
            ll it = upper_bound(mp[s[i]-'a'].begin(), mp[s[i]-'a'].end(), i) - mp[s[i]-'a'].begin() -1;
            if((it < 0 || it >= mp[s[i]-'a'].size()) || mp[s[i]-'a'][it] <= left) {
                mp[s[i]-'a'].push_back(i);
            }
            else {
                incl += 2;
                left = i;
            }
        }

        // cout << incl << endl;

        ll ans = n - incl;
        cout << ans << endl;
    }
}