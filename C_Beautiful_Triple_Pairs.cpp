#include <bits/stdc++.h>

#define ll long long

using namespace std;

void mapInMap(map<vector<int>, int> &mp,  map<vector<int>, int> &mp2, vector<int> &arr) {
    mp[{-1, arr[1], arr[2]}]++;
    mp[{arr[0], -1, arr[2]}]++;
    mp[{arr[0], arr[1], -1}]++;
    mp2[arr]+=3; 
}

ll checkInMap( map<vector<int>, int> &mp,map<vector<int>, int> &mp2, vector<int> &arr) {
    ll ans = 0;
    ans += mp[{-1, arr[1], arr[2]}];
    ans += mp[{arr[0], -1, arr[2]}];
    ans += mp[{arr[0], arr[1], -1}];
    ans -= mp2[arr];
    return ans;
}

int main() {
    int tc = 0; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        int n; cin >> n;
        vector<ll> arr(n, 0);
        for(int i = 0; i < n; i++) cin >> arr[i];

        if(n < 2) {
            cout << 0 << endl;
            continue;
        }

        map<vector<int>, int> mp;
        map<vector<int>, int> mp2;
        vector<int> a(3, -1);
        ll ans = 0;
        for(int i = 0; i <= 2; i++) {
            a[i] = arr[i];
        }

        mapInMap(mp, mp2, a);

        for(int i = 3; i < n; i++) {
            a[0] = a[1];
            a[1] = a[2];
            a[2] = arr[i];
            ll t = checkInMap(mp, mp2, a);
            //cout << t << endl;
            ans += t;
            mapInMap(mp, mp2, a);
        }       

        cout << ans << endl;
    }
}