#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n, k; cin >> n >> k;
        vector<ll> ans(n);


        ll left = 1, right = n;
        bool l = 1;
        for(ll i = 0; i < k; i++) {
            for(ll j = i; j < n; j+=k) {
                if(l) ans[j] = left++;
                else ans[j] = right--;
            }
            l = !l;
        }

        for(auto v: ans) cout << v << " ";
        cout << endl;

    }
}