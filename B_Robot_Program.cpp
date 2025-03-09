#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n, x, k; cin >> n >> x >> k;
        string s; cin >> s;

        ll cnt = 0;
        for(int i = 0; i < s.size() && x != 0; i++) {
            if(s[i] == 'L') x--;
            else x++;
            cnt++;
            if(x == 0) break;
        }

        if(x != 0) {
            cout << 0 << endl;
            continue;
        }
  
        ll nextCnt = 0;
        bool flag = 0;
        for(ll i = 0; i < s.size(); i++) {
            if(s[i] == 'L') x--;
            else x++;

            nextCnt++;
            if(x == 0) {
                flag = 1;
                break;
            }
        }
        
        if(!flag) {
            cout << 1 << endl;
            continue;
        }

        ll ans = 1 + (k - cnt)/nextCnt;
        cout << ans << endl;
    }
}