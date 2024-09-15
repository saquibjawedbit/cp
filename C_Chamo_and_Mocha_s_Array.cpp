#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tc; cin >> tc;
    for(int t =1; t <= tc; t++) {
        int n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        vector<ll> ans;
        for(int i = 0; i < n-1; i++) ans.push_back(min(a[i], a[i+1]));
        for(int i = 0; i < n-2; i++) ans.push_back(min(a[i], max(a[i+1], a[i+2])));

        cout << *max_element(ans.begin(), ans.end()) << endl;
    }
}