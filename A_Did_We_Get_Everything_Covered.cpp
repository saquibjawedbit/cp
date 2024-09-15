#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n, k, m; cin >> n >> k >> m;
        string s; cin >> s;
        set<char> st;
        // map<char, int> ct;
        string ans = "";
        ll index = 0, counter = 0;
        while(index < s.size()) {
            st.insert(s[index]);
            //ct[s[index]]++;
            if(st.size() == k) {
                ans.push_back(s[index]);
                st.clear();
                counter++;
            }
            index++;
        }
        if(counter >=  n) cout << "YES" << endl;
        else {
            cout << "NO" << endl;
            char ch = 'a';
            for(auto v: st) {
                if(ch != v) break;
                ch++;
            }
            while(ans.length() != n) ans.push_back(ch);
            cout << ans << endl;
            // bool ans = false;
            // for(char ch = 'a'; ch < 97+k; ch++) {
            //     if(ct[ch] < n) {
            //         for(ll i = 0; i < n; i++) cout << ch;
            //         ans = true;
            //         cout << endl;
            //         break;
            //     }
            // }
            // if(!ans) {
            //     char ch = 'a';
            //     ll index = 0;
            //     for(auto v: st) {
            //         index++;
            //         cout << v;
            //         if(v != ch) {
            //             break;
            //         }
            //         ch++;
            //     }
            //     for(ll i = index; i < n; i++) cout << ch;
            //     cout << endl;
            // }
        }
    }
}