#include <bits/stdc++.h>


using namespace std;

#define ll long long

int main() {

    ios_base::sync_with_stdio(false);  // Disable sync with C I/O
    cin.tie(nullptr); 
    ll tc = 1;
    cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(auto &v: a) cin >> v;

        bool ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (2 * a[i] > a[i + 1] and 2 * a[i + 1] > a[i]) ans = 1;
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}