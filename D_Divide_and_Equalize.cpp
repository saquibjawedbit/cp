#include <bits/stdc++.h>

using namespace std;

#define ll long long

void getPrime(ll v, unordered_map<ll, ll> &mp) {
    while(v % 2 == 0) {
        mp[2]++;
        v /= 2;
    }

    for(int i = 3; i <= sqrt(v); i++) {
        ll cnt = 0;
        while(v % i == 0) {
            cnt++;
            v /= i;
        }
        mp[i] += cnt;
    }

    if(v > 1) mp[v]++;
}

int main() {
    int tc = 1;
    cin >> tc;
    for(int t =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        unordered_map<ll, ll> cnt;
        for(auto v: arr) {
            getPrime(v, cnt);
        }

        bool ans = true;
        for(auto v: cnt) {
            if(v.second % n != 0) {
                ans = false;
                break;
            }
        }

        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}