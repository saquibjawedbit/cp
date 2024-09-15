#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    int tc= 1;
    cin >> tc;
    for(int t =1; t <= tc; t++) {
        ll n; cin >> n;
        string s; cin >> s;

        //For Count 1
        vector<bool> check(26, 0);
        for(auto v: s) {
            check[v-97] = 1;
        }

        string ans = "";
        for(int i = 0; i < 26; i++) {
            if(check[i] == 0) {
                ans.push_back(i+97);
                break;
            }
        }
        if(ans != "") {
            cout << ans << endl;
            continue;
        }

        //For Count = 2
        map<string, bool> mp;
        for(int i = 0; i < n-1; i++) {
            mp[s.substr(i, 2)] = 1;
        }

        int left = 97, right = 97;
        for(auto v: mp) {
            if(v.first[0] == left && v.first[1] == right) {
                right++;
                if(right == 'z'+1) {
                    left++;
                    right ='a';
                }
            }
            else {
                ans.push_back(left);
                ans.push_back(right);
                break;
            }
        }

        if(ans != "") {
            cout << ans << endl;
            continue;
        } 

        mp.clear();

        for(int i = 0; i < n-2; i++) {
            mp[s.substr(i, 3)] = 1;
        }

        left = 97, right = 97;
        for(auto v: mp) {
            if(v.first[0] == 'a' && v.first[1] == left && v.first[2] == right) {
                right++;
                if(right == 'z'+1) {
                    left++;
                    right ='a';
                }
            }
            else {
                ans.push_back('a');
                ans.push_back(left);
                ans.push_back(right);
                break;
            }
        }

        cout << ans << endl;


    } 

}