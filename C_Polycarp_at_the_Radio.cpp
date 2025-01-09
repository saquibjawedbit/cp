#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // ll n; cin >> n;
    // vector<ll> arr(n);

    // for(auto &v: arr) cin >> v;

    // map<ll, ll> mp;

    // for(auto v: arr) {
    //     mp[v]++;
    // }

    // for(auto v: mp) {
    //     cout << v.first << " " << v.second << "\n";
    // }

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);

    for(auto &v: a) cin >> v;

    ll ans = 0;
    ll avg = a.size() / m;
    vector<ll> mp(m+1, 0);
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] <= m) mp[a[i]]++;
    }


    for(int i = 1; i <= m; i++) {
        if(mp[i] < avg) {
            ans += (avg - mp[i]);
        }
    }

    ll changes = 0;
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] > m) {
            ll key = 0;
            for(int j = 1; j <= m; ++j) {
                if(mp[j] < avg) {
                    key = j;
                    mp[j]++;
                    break;
                }
            }
            if(key != 0) a[i] = key;
        }
    }

    for(int i = 0; i < a.size(); ++i) {
        if(a[i] <= m &&  mp[a[i]] > avg) {
            ll key = 0;
            for(int j = 1; j <= m; ++j) {
                if(mp[j] < avg) {
                    key = j;
                    mp[j]++;
                    mp[a[i]]--;
                    break;
                }
            }
            if(key != 0) a[i] = key;
        }
    }
    
    cout << avg << " " << ans << "\n";
    for(auto v: a) cout << v << " ";
    cout << endl;
    
}