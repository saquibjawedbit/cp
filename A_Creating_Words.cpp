#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        string a, b; cin >> a >> b;
        swap(a[0], b[0]);
        cout << a << " " << b << endl;
    }
}