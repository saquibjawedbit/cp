#include <bits/stdc++.h>

#define ll long long

using namespace std;

void mapInMap(map<vector<int>, int> &mp, vector<int> &arr) {
    mp[{-1, arr[1], arr[2]}]++;
    mp[{arr[0], -1, arr[2]}]++;
    mp[{-1, arr[1], arr[2]}]++;
}

int checkInMap(map<vector<int>, int> &mp, vector<int> &arr) {
    int ans = 0;
    ans += mp[{-1, arr[1], arr[2]}];
    ans += mp[{arr[0], -1, arr[2]}];
    ans += mp[{-1, arr[1], arr[2]}];
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
        vector<int> a(3, -1);
        int ans = 0;
        for(int i = 0; i <= 2; i++) {
            a[i] = arr[i];
        }

        mapInMap(mp, a);

        for(int i = 3; i < n; i++) {
            a[0] = a[1];
            a[1] = a[2];
            a[2] = arr[i];
            ans += checkInMap(mp, a);
            mapInMap(mp, a);
        }       

        cout << ans << endl;
    }
}