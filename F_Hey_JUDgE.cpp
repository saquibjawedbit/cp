#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        string s; cin >> s;

        vector<ll> arr;
        map<ll, ll> mp;

        for(auto v: s) {
            arr.push_back(v - 'A' + 1);
        }

        sort(arr.begin(), arr.end());

        vector<ll> freq(6, 0);

        ll index = 0;
        while(index < arr.size()) {
            if(freq[arr[index]] != 0) {
                arr.erase(arr.begin() + index);
            } 
            else {
                freq[arr[index]]++;
                index++;
            }
        }

        set<pair<ll, ll>> st;
        auto solve = [&](ll end, ll target) -> bool {
            for(int i = 0; i <= end; i++) {
                for(int j = i+1; j <= end; j++) {
                    ll sum = arr[i] + arr[j];
                    if(sum == target && st.find({i, j}) == st.end()) {
                        return true;
                    }
                }
            }
            return false;
        };

        bool ans = true;
        for(int i = 1; i <= 5; i++) {
            if(freq[i] == 0) {
                bool isPossible = solve(i-1, i);
                if(!isPossible) {
                    ans = false;
                    break;
                }
            }
        }

        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }
}