#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc = 0; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        int n; cin >> n;
        string s; cin >> s;

        map<char, int> mp;
        for(auto v: s) mp[v]++;

        int nNorths = mp['N'] - mp['S'];
        int nEasts = mp['E'] - mp['W'];

        if((nNorths&1) == 1 || (nEasts&1) == 1 || (nNorths == 0 && nEasts == 0 && n <= 2)) {
            cout << "NO" << endl;
        }
        else {
            
            int nNorth =  mp['N']/2, nSouth = mp['S']/2;
            int nWest = mp['W']/2, nEast = mp['E']/2;


            string ans = "";
            for(int i = 0; i < n; i++) {
                if(s[i] == 'N') {
                    if(nNorth-- > 0) ans += 'R';
                    else ans += 'H';
                }
                else if(s[i] == 'S') {
                    if(nSouth-- > 0) ans += 'R';
                    else ans += 'H';
                }
                else if(s[i] == 'E') {
                    if(nEast-- > 0) ans += 'H';
                    else ans += 'R';
                }
                else {
                    if(nWest-- > 0) ans += 'H';
                    else ans += 'R';
                }
            }
            cout << ans << endl;
        }


    }
}