#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tc = 1;
    cin >> tc;
    for(int t =1; t <= tc; t++) {
        ll n; cin >> n;

        vector<ll> arr(n);

        for(auto &v: arr) cin >> v;

        if(n == 1) {
            cout << 1 << endl;
            continue;
        }

        map<ll, ll> count;
        map<ll, bool> inc;
        for(auto v: arr) count[v]++;

        ll ans = 0;
        for(auto v: count) {
            if(v.second > 1) {
                count[v.first+1]++;
                if(count[v.first+1] == 1) inc[v.first+1] = 1;
            }
        }

        ll prev = -1;
        ll cnt = 0, str = -1;
        for(auto v: count) {
            if(prev + 1 == v.first) {
                cnt++;
            }
            else {
                while(count[str] > 0 && !inc[str]) {
                    cnt++; str--;
                }
                ans = max(ans, cnt);
                cnt = 1;
                str = v.first-2;
            }
            prev = v.first;
        }
        while(count[str] > 0 && !inc[str]) {
            cnt++; 
            str--;
        }
        ans = max(ans, cnt);
        cout << ans << endl;
    }
}