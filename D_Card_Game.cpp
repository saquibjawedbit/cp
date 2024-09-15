#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tc = 1; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        int n; cin >> n;
        char trump; cin >> trump;
        map<char, vector<int>> mp;
        for(int i = 0; i < (2 * n); i++) {
            int val; cin >> val;
            char ch; cin >> ch;
            mp[ch].push_back(val);
        }

        for(auto v: mp) {
            sort(v.second.begin(), v.second.end());
            mp[v.first] = v.second;
        }

        vector<string> ans;
        int index = 0;
        for(auto v: mp) {
            int j = 0;
            if(v.first == trump) continue;
            while(j < v.second.size()) {
                string str1 = to_string(v.second[j++]) + v.first;
                string str2;
                if(j < v.second.size()) str2 = to_string(v.second[j++]) + v.first;
                else if(index < mp[trump].size()) str2 = to_string(mp[trump][index++]) + trump;
                else break;
                ans.push_back(str1 + " " + str2);
            }
        }

        while(index < mp[trump].size()) {
            string str1 = to_string(mp[trump][index++]) + trump;
            string str2;
            if(index < mp[trump].size()) str2 = to_string(mp[trump][index++]) + trump;
            ans.push_back(str1 + " " + str2);
        }

        if(ans.size() != n) cout << "IMPOSSIBLE" << endl;
        else {
            for(auto v: ans) cout << v << endl;
        }
    }
}