#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int maxi = 0, mini = 0;
    bool start = true;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if(start) {
            mini = a;
            start = false;
        }

        maxi = maxi | a;
        mini = mini & a;
    }

    cout << maxi - mini << endl;
}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();
    return 0;
}