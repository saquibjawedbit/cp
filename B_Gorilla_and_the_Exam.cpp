#include <bits/stdc++.h>


using namespace std;

#define ll long long
#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);  // Disable sync with C I/O
    cin.tie(nullptr); 
    cout.tie(nullptr);
    ll tc = 1;
    cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        map<ll, ll> mp;
        for(auto v: arr) {
            mp[v]++;
        }

        ll maxi = 0, maxElement = -1;
        for(auto v: mp) {
            if(v.second > maxi) {
                maxi = v.second;
                maxElement = v.first;
            }
        }

        vector<pair<ll, ll>> freq((ll)mp.size());
        for(auto &v: mp) {
            freq.push_back({v.first, v.second});
        }

        sort(freq.begin(), freq.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });

        for(auto &v : freq){
            if(v.first == maxElement) continue;
            if(k == 0) break;

            ll freq1 = v.second;
            if(freq1 <= k){
                v.second = 0; 
                mp[maxElement] += freq1;
                k -= freq1;
            } else {
                v.second -= k;
                mp[maxElement] += k;
                k = 0;
                break;
            }
        }
        ll ans = 0;
        for(auto &it : freq){
            mp[it.first] = it.second;
        }
        for(auto &it : mp){
            if(it.second > 0) ans++;
        }

        cout << ans << "\n";
    }   
}