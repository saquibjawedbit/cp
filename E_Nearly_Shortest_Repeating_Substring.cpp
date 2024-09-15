#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

bool solve(string &s, int factor) {
    int pDiff = 0;
    int sDiff = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[(i % factor)] != s[i]) pDiff++;
        if(s[(i % factor) + (s.length()-factor)] != s[i]) sDiff++;
    }

    return (pDiff <= 1 || sDiff <= 1);
}



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        string s; cin >> s;


        vector<int> factors;
        for(int i = 1; i <= n; i++) {
            if(n % i == 0) {
                factors.push_back(i);
            }
        }
        ll ans = n;
        for(auto v: factors) {
            bool match = solve(s, v);
            if(match) {
                ans = v;
                break;
            }
        }
        cout << ans << endl;
    }
}
