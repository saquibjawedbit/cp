#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    string ans = "";
    stack<char> t;

    vector<int> freq(26, 0);

    for(auto v: s) freq[v-'a']++;
    int index = 0;

    for(int i = 0; i < s.size(); i++) {
        while(index < 26 && freq[index] <= 0) {
            index++;
        }

        if((s[i] -'a') == index) ans.push_back(s[i]);
        else {
            t.push(s[i]);
        }
        freq[s[i]-'a']--;

        while(index < 26 && freq[index] <= 0) {
            index++;
        }

        while(!t.empty() && t.top() <= ('a' + index)) {
            ans.push_back(t.top());
            t.pop();
        }
    }

    while(!t.empty()) {
        ans.push_back(t.top());
        t.pop();
    }

    cout << ans << endl;
}