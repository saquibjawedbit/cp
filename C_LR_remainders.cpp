#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tc=1; cin >> tc;
    for(int t =1; t <= tc; t++) {
        int n, m; cin >> n >> m;
        vector<ll> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        string s; cin >> s;
        int left = 0, right = s.size()-1, index = 0;
        while(right >= left) {
            if(s[index++] == 'L') left++;
            else right--;
        }
        index = n-1;
        ll prod = 1;
        vector<ll> ans;
        while(left != 0 || right != n-1) {
            if(s[index--] == 'L') {
                left--;
                prod = ((prod % m) * (arr[left] % m)) % m;
                ans.push_back(prod);
            }
            else {
                right++;
                prod = ((prod % m) * (arr[right] % m)) % m;
                ans.push_back(prod);
            }
        }
        reverse(ans.begin(), ans.end());
        for(auto v: ans) cout << v << " ";
        cout << endl;

    }
}