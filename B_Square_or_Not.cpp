#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007




int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        string s; cin >> s;

        int val = sqrt(n);
        bool ans = ((val * val) == n) ? true : false;

        if(!ans) {
            cout << "No" << endl;
        }
        else {
            bool error = false;
            //Side Check
            for(int i = 0; i < val; i++) {
                if(s[i] != '1') {
                    error = true;
                    break;
                }
            }

            for(int i = val; i < s.size()-val; i++) {
                if(i % val == 0 || i % val == val - 1) {
                    if(s[i] != '1') {
                        error = true;
                        break;
                    }
                }
                else if(s[i] != '0') {
                    error = true;
                    break;
                }
            }

            for(int i = s.size()-val ; i < s.size(); i++) {
                if(s[i] != '1') {
                    error = true;
                    break;
                }
            }

            if(error) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
} 