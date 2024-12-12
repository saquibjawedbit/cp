#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc=1; cin >> tc;
    for(ll t =1; t <= tc; t++) {
        ll n; cin >> n;
        string s; cin >> s;

        ll cnt = 0;
        for(auto v: s) if(v == '*') cnt++;

        ll ans = 0;

        if(cnt&1) {
            ll mid = (cnt >> 1) + 1;
            ll index = -1, counter = 0, pre = 0;
            for(int i = 0; i < n; i++) {
                if(s[i] == '*') {
                    counter++;
                    if(counter == mid) {
                        index = i;
                        pre = i+1;
                    }
                    else if(counter > mid) {
                        ans += (i-pre);
                        pre++;
                    }
                }
            }

            pre = index-1;
            for(int i = 0; i < index; i++) {
                if(s[i] == '*') {
                    ans += (pre - i);
                    pre--;
                }
            } 
        }

        else {
            ll mid = (cnt >> 1);
            ll index = -1, counter = 0, pre = 0;
            for(int i = 0; i < n; i++) {
                if(s[i] == '*') {
                    counter++;
                    if(counter == mid) {
                        index = i;
                        pre = i+1;
                    }
                    else if(counter > mid) {
                        ans += (i-pre);
                        pre++;
                    }
                }
            }

            pre = index-1;
            for(int i = 0; i < index; i++) {
                if(s[i] == '*') {
                    ans += (pre - i);
                    pre--;
                }
            } 

            ll nAns = 0;
            mid = (cnt >> 1) + 1;
            index = -1, counter = 0, pre = 0;
            for(int i = 0; i < n; i++) {
                if(s[i] == '*') {
                    counter++;
                    if(counter == mid) {
                        index = i;
                        pre = i+1;
                    }
                    else if(counter > mid) {
                        nAns += (i-pre);
                        pre++;
                    }
                }
            }

            pre = index-1;
            for(int i = 0; i < index; i++) {
                if(s[i] == '*') {
                    nAns += (pre - i);
                    pre--;
                }
            } 

            ans = min(ans, nAns);
        }

        cout << ans << endl;
    }
}