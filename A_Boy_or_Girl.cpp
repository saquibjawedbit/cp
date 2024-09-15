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
        vector<int> freq(26, 0);

        for(auto v: s) {
            freq[v-97]++;
        }

        int cnt = 0;
        for(auto v: freq) {
            if(v != 0) cnt++;
        }

        if(cnt&1) cout << "IGNORE HIM!" << endl;
        else cout << "CHAT WITH HER!" << endl;
        

    }
} 