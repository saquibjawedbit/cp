#include <iostream>

using namespace std;

int main() {
    int t; cin >> t;
    while(t-- > 0) {
        string s; cin >> s;
        int ans = 1;
        bool isPresent = 0;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] != s[i-1]) ans++;
            if(s[i] == '1' && s[i-1] == '0') isPresent = 1;
        }

        cout << ans - isPresent << endl;
    }

    return 0;
}