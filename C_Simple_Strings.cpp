#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    //cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        string s; cin >> s;

        for(int i = 1; i < s.length(); i++) {
            if(s[i-1] == s[i]) {
                s[i] = 'a';
                while(s[i-1] == s[i] || ((i+1) < s.length() && s[i] == s[i+1])) s[i]++;
            }
        }

        cout << s << endl;        
    }
} 
