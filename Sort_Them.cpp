// cook your dish here
#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll getAns(string &s, int index, char prevChar, map<char, char> &mp, vector<vector<ll>> &dp) {
    if(index >= s.size()) return 0;

    if(dp[index][prevChar-'a'] != -1) {
        return dp[index][prevChar-'a'];
    } 
    
    char cChar = s[index];
    char nChar = mp[cChar];
    
    ll c = INT_MAX, n = INT_MAX;
    if(prevChar <= cChar && prevChar <= nChar) {
        c = getAns(s, index+1, cChar, mp, dp);
        n = getAns(s, index+1, nChar, mp, dp) +1;
        
    }
    else if(prevChar <= cChar) {
        c = getAns(s, index+1, cChar, mp, dp);
    
    }
    else if(prevChar <= nChar) {
        n = getAns(s, index+1, nChar, mp, dp) + 1;
    }
    
    dp[index][prevChar-'a'] = min(n, c);
    return dp[index][prevChar-'a'];
    
}


int main() {
    ll tc; cin >> tc;
    while(tc-- > 0) {
        ll n; cin >> n;
        string s, p; cin >> s >> p;
        
        map<char, char> mp;
        ll left = 0, right = p.size()-1;
        while(right >= left) {
            mp[p[left]] = p[right];
            mp[p[right]] = p[left];
            left++; right--;
        }

        vector<vector<ll>> dp(n, vector<ll>(27, -1));
        ll score = getAns(s, 0, 'a', mp, dp);
        
        if(score == INT_MAX) cout << -1 << endl;
        else cout << score << endl;
        
    }
}