#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n, x; cin >> n;
        vector<ll> ans;
        int order = 1;
        while(n != 0) {
            ll digit = (n % 10) * order;
            if(digit != 0) ans.push_back(digit);
            n = n / 10;
            order *= 10;
        }

        cout << ans.size() << endl;
        for(auto &v: ans) cout << v << " ";
        cout << endl;

    }
} 