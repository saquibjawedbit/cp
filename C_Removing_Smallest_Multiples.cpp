#include <bits/stdc++.h>

using namespace std;

#define ll long long

using namespace std;



int main() {
    int tc = 1; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        ll n; cin >> n;
        string s; cin >> s;
        vector<bool> isVisited(n, 0);
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            ll k = 1;
            while((i * k) <= n && s[(i*k) - 1] == '0') { 
                if(!isVisited[(i*k)-1]) ans += i;
                isVisited[(i*k)-1] = 1;
                k++;
            }
        }
        cout << ans << endl;
    }
}