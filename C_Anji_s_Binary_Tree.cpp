#include <bits/stdc++.h>

using namespace std;

int solve(int index, string &s, vector<pair<int, int>> &arr) {
    if(index > arr.size()) return 0;
    if(index == 0) return INT_MAX-2;
    if(arr[index].first == 0 && arr[index].second == 0) return 0;

    int l = solve(arr[index].first, s, arr);
    int r = solve(arr[index].second, s, arr);

    if(s[index-1] != 'L') l++;
    if(s[index-1] != 'R') r++;

    return min(l, r);
}

int main() {
    int tc; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        int n; cin >> n;
        string s; cin >> s;
        vector<pair<int, int>> arr(n+1);
        for(int i = 1; i <= n; i++) {
            int u, v; cin >> u >> v;
            arr[i] = {u, v};
        }

        int ans = solve(1 ,s, arr);
        cout << ans << endl;
    }
}