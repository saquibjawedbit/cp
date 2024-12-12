#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int n; cin >> n;
    vector<ll> arr(n-1);
    for(auto &v: arr) cin >> v;

    sort(arr.begin(), arr.end());

    ll v = 1;
    for(auto &s: arr) {
        if((v) != s) break;
        v++;
    }

    cout << v << endl;

    return 0;
}