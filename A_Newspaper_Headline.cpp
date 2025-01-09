#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    string s, t; cin >> s >> t;

    vector<vector<ll>> freq(26);

    ll ans = 1;
    for(int i = 0; i < s.size(); i++) {
        freq[s[i]-'a'].push_back(i);
    }

    ll prevIndex = -1;
    for(int i = 0; i < t.size(); i++) {
        if(freq[t[i] - 'a'].empty()) {
            ans = -1;
            break;
        }
        else {
            auto cVal = upper_bound(freq[t[i]-'a'].begin(), freq[t[i]-'a'].end(), prevIndex);
            if(cVal == freq[t[i]-'a'].end() || *cVal <= prevIndex) {
                ans++;
                prevIndex = freq[t[i]-'a'][0];
            }
            else {
                
                prevIndex = *cVal;
            }
        }
    }

    cout << ans << endl;
}