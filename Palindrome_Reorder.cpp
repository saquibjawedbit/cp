#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    string s; cin >> s;
    ll left = 0, right = s.size()-1;

    map<char, ll> mp;

    for(auto v: s) mp[v]++;

    vector<int> parity(2, 0);

    char odd = ' ';
    for(auto v: mp) {
        if(v.second&1) odd = v.first;
        parity[v.second&1]++;
    }

    if(parity[1] > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    s = "";

    for(auto v: mp) {
        if(v.first == odd) continue;
        for(int i = 0; i < (v.second/2); i++) {
            s.push_back(v.first);
        }
    }

    for(int i = 0; i < mp[odd]; i++) {
        s.push_back(odd);
    }
    string ns = "";
    for(auto v: mp) {
        if(v.first == odd) continue;
        for(int i = 0; i < (v.second/2); i++) {
            ns.push_back(v.first);
        }
    }

    for(int i = ns.size()-1; i >= 0; i--) s.push_back(ns[i]);

    cout << s << endl;


}