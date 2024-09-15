#include <bits/stdc++.h>

using namespace std;

#define ll long long


ll check(string &s, char ch) {
    ll left = 0, right = s.length()-1;
    ll cnt = 0;
    while(right >= left) {
        if(s[left] == s[right]) {
            left++; right--;
        }
        else if(s[right] == ch) {
            right--; cnt++;
        }
        else if(s[left] == ch) {
            left++; cnt++;
        }
        else {
            return -1;
        }
    }
    return cnt;
}

int main() {
    ll tc =1;
    cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n; cin >> n;
        string s; cin >> s;
        bool answer = false;

        ll left = 0, right = s.length()-1;
        char a = ' ', b =' ';
        while(right >= left) {
            if(s[right] == s[left]) {
                right--; left++;
            }
            else {
                a = s[right];
                b = s[left];
                break;
            }  
        }

        if(a == ' ' && b == ' ') {
            cout << 0 << endl;
            continue;
        }

        ll l1 = check(s, a);
        ll l2 = check(s, b);

        if(l1 != -1 && l2 != -1) {
            cout << min(l1, l2) << endl;
        }
        else if(l1 != -1) {
            cout << l1 << endl;
        }
        else if(l2 != -1) {
            cout << l2 << endl;
        }
        else {
            cout << -1 << endl;
        }


    }
}