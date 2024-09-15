#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<char> values = {'n', 'a', 'r', 'e', 'k'};

ll solve(vector<string> &val, string &s, ll index, ll &m, vector<ll> &dp) {
    if(index >= val.size()) {
        //Calculate
            ll sc1 = 0, sc2 = 0;
            ll index = 0;
            for(auto v: s) {
                if(values[index] == v) {
                    index = (index + 1) % 5;
                    sc1++;
                } 
                else if(v == 'n' || v == 'a' || v == 'r' || v == 'e' || v == 'k') {
                    sc2++;
                }
            }
            ll totalScore = (sc1/5 * 5) - sc2 - index;
            return totalScore;
    }

    s += (val[index]);
    ll left = solve(val, s, index +1, m, dp);
    for(int i = 0; i < m; i++) s.pop_back();

    ll right = solve(val, s, index + 1, m, dp);
    dp[index] = max(left, right);
    return max(left, right);
}


int main() {
    int tc= 1;
    cin >> tc;
    for(int t =1; t <= tc; t++) {
        ll n, m; cin >> n >> m;
        vector<string> arr(n);

        for(auto &v: arr) cin >> v;
        vector<ll> dp(n+1, -1);
        string s = "";
        ll ans = solve(arr, s, 0, m, dp);
        // for(auto s: arr) {
        //     ll index = 0;
        //     ll sc1 = 0, sc2 = 0;
        //     for(auto v: s) {
        //         if(values[index] == v) {
        //             index = (index + 1) % 5;
        //             sc1++;
        //         } 
        //         else if(v == 'n' || v == 'a' || v == 'r' || v == 'e' || v == 'k') {
        //             sc2++;
        //         }
        //     }
        //     ll totalScore = (sc1/5 * 5) - sc2;
        //     if(totalScore >= 0) {
        //         ans += totalScore;
        //     }
        // }
        cout << ans << endl;


    } 

}