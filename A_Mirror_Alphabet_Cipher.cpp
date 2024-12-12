#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tc = 1;
    //cin >> tc;
    for(int t =1; t <= tc; t++) {
        string s; cin>> s;
        string ns = "";

        map<char, char> mp;
        for (char c = 'a'; c <= 'z'; c++) mp[c] = 'z' - (c - 'a');


        for(auto v: s) {
            ns.push_back(mp[v]);
        }

        cout << ns << endl;
    }
}