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
    
        ll left = 0;
        while(s[left] == 'o') left++;

        vector<pair<char,ll>> arr;
        arr.push_back({'v', 1});
        for(int i = left+1; i < s.length(); i++) {
            if(arr[arr.size()-1].first == s[i]) {
                arr[arr.size()-1].second++;
            }
            else {
                arr.push_back({s[i], 1});
            }
        }

        ll tv = 0;
        for(auto v: arr) {
            if(v.first == 'v') {
                tv += (v.second-1);
            }
        }

        left = 0; ll ans = 0;
        for(auto v: arr) {
            if(v.first == 'v') {
                left += (v.second-1);
            }
            else {
                ans += (left * v.second * (tv - left));
            }
        }

        cout << ans << endl;
    }
} 
