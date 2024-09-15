#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t-- > 0) {
        int n; cin >> n;
        map<int, vector<int>> mp;
        map<int, int> c;
        vector<vector<int>> arr(n);
        for(int i = 0; i < n; i++) {
            int k; cin >> k;
            vector<int> temp(k);
            for(int j = 0; j < k; j++) {
                cin >> temp[j];
                mp[temp[j]].push_back(i);
                c[temp[j]]++;
            }
            arr[i] = temp;
        }
        int ans = 0;
        for(auto v: mp) {
            map<int, int> nm = c;
            for(auto n: v.second) {
                for(int i = 0; i < arr[n].size(); i++) {
                    nm[arr[n][i]]--;
                }
            }
            int count = 0;
            for(auto z: nm) {
                if(z.second != 0) count++;
            }
            //cout << count << endl;
            if(count == c.size()) continue;
            ans = max(ans, count);
        }
        cout << ans << endl;
    }
}