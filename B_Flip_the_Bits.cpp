#include <iostream>

using namespace std;


void solve() {
    int n; cin >> n;
    string source, target; cin >> source >> target;

    int ones = 0, zeros = 0;
    for(int i = 0; i < n; i++) {
        if(source[i] == '1') ones++;
        else zeros++;
    }

    bool ans = true;
    bool cCondition = 1;

    for(int i = n-1; i >= 0; i--) {
        bool isSame = source[i] == target[i] ? 0 : 1;
        if(isSame == cCondition && zeros == ones) {
            cCondition = !cCondition;
        }
        else if(isSame == cCondition) {
            ans = false;
            break;
        }

        if(source[i] == '0') zeros--;
        else ones--;
    }

    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();
}