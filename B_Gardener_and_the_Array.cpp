#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc = 0; cin >> tc;
    for(int t = 0; t < tc; t++) {
        int n; cin >> n;
        bool ans = false;
        map<int, int> mp;
        vector<vector<int>> arr(n);
        for(int i = 0; i < n; i++) {
            int k; cin >> k;
            vector<int> temp(k , 0);
            for(int j = 0; j < k; j++) {
                cin >> temp[j];
                mp[temp[j]]++;
            }
            arr[i] = temp;
        }
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < arr[i].size(); j++) {
                if(mp[arr[i][j]] > 1) count++;
                else break;
            }
            if(count == arr[i].size()) {
                ans = true;
                break;
            }
        }
        if(ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

}