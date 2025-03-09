#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1; //cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n; cin >> n;
        
        vector<pair<ll,ll>> arr;

        map<pair<ll,ll>, vector<ll>> mp;
        for(int i = 0; i < n; i++) {
            ll a, b; cin >> a >> b;
            arr.push_back({a, b}); 
            mp[{a,b}].push_back(i+1);

        }

        sort(arr.begin(), arr.end(), [](pair<ll, ll> a , pair<ll, ll> b) {
            if(a.first == b.first) return a.second > b.second;

            return a.first < b.first;
        });

        ll left = -1, right = -1;
        for(ll i = 1; i < arr.size(); i++) {
            if(arr[i-1].first <= arr[i].first && arr[i-1].second >= arr[i].second) {
                left = mp[arr[i-1]].front(); right = mp[arr[i]].back();
                break;
            }
        }

        cout << right << " " << left << endl;
    }
}