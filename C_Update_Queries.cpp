
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n, m; cin >> n >> m;;
        string s; cin >> s;
        vector<ll> arr(m);
        for(auto &v: arr) cin >> v;
        string c; cin >> c;

        sort(arr.begin(), arr.end());
        sort(c.begin(), c.end());

        vector<ll> mp(n+1, -1);

        int index = 0;
        for(int i = 0; i < m; i++) {
            if(mp[arr[i]] != -1) {
                arr.pop_back();
                continue;
            }
            s[arr[i]-1] = c[index++]; 
            mp[arr[i]] = 1;
        }
        cout << s << endl;
    }
}