#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    int tc = 1;
    cin >> tc;
    for(int t =1; t <= tc; t++) {
        ll n; cin >> n;
        string s; cin >> s;

        ll sum = 0;
        for(auto v: s) sum += (v == '(') ? 1 : -1;

        if(sum != 0) {
            cout << -1 << endl;
            continue;
        }
        
        vector<vector<ll>> ans(2);
        stack<char> st, rt;
        ll index = 0;
        for(auto v: s) {
            if(v == '(' && rt.empty()) {
                st.push(v);
                ans[0].push_back(index);
            }
            else if(v == ')' && !st.empty()) {
                st.pop();
                ans[0].push_back(index);
            }
            else if(v == ')' && st.empty()) {
                rt.push(v);
                ans[1].push_back(index);
            }
            else {
                rt.pop();
                ans[1].push_back(index);
            }
            index++;
        }

        if(ans[0].size() != 0 && ans[1].size() != 0) {
            cout << 2 << endl;
            ll left = 0, right = 0;
            while(left < ans[0].size() && right < ans[1].size()) {
                if(ans[0][left] < ans[1][right]) {
                    left++;
                    cout << 1 << " ";
                }
                else {
                    right++;
                    cout << 2 << " ";
                }
            }

            while(left++ < ans[0].size()) cout << 1 << " ";
            while(right++ < ans[1].size()) cout << 2 << " "; 
        }
        else {
            cout << 1 << endl;
            if(!ans[0].empty()) for(auto v: ans[0]) cout << 1 << " ";
            if(!ans[1].empty()) for(auto v: ans[1]) cout << 1 << " ";
        } cout << endl;
    }
}