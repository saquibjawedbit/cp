#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> check(vector<int> &arr, ll mid) {
    ll cp = 0;
    vector<int> ans;
    for(int i = 0; i < arr.size(); i++) {
        ll temp = (mid/arr[i]) + 1;
        ans.push_back(temp);
        cp += temp;
        if(cp > mid) {
            vector<int> n = {-1};
            return n;
        }
    }

    for(int i = 0; i < arr.size(); i++) {
        ll sp = arr[i] * ans[i];
        if(sp < cp) {
            vector<int> n = {-2};
            return n;
        }
    }

    return ans;
}


int main() {
    int tc = 1; cin >> tc;
    for(int t =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<int> arr(n, 0);
        for(int i = 0; i < n; i++) cin >> arr[i];
        vector<int> prifts;

        ll left = 1, right = 1e9;
        while(right > left) {
            ll mid = right + (left -right)/2;
            prifts = check(arr, mid);
            if(prifts[0] == -1) {
                left = mid +1;
            }
            else if(prifts[1] == -1)  {
                right = mid -1;
            }
            else {
                break;
            }
        }

        if(prifts[0] == -1 || prifts[0] == -2) cout << -1 << endl;
        else {
            for(auto v: prifts) {
                cout << v << " ";
            } cout << endl;
        }
    }
}