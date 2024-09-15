#include <bits/stdc++.h>

using namespace std;

int main() {
    int t = 1; //cin >> t;
    for(int i = 1; i <= t; i++) {
        int n; cin >> n;
        long long ans = 0;
        map<long long , long long> mp;
        while(n-- > 0) {
            string s; cin >> s;
            
            int  mask = 0;
            //Step 1: Convert to mask
            for(auto ch: s) {
                mask ^= (1 << (ch - 'a'));
            }

            //Step 2: Count
            ans += mp[mask];

            //Step 3: Odd case

            for(int i = 0; i < 26; i++) {
                mask ^= (1 << i);
                ans += mp[mask];
                mask ^= (1 << i);
            }

            mp[mask]++;
        }
        cout << ans << endl;

    }
}

