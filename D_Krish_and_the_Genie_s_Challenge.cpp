#include <bits/stdc++.h>
using namespace std;

#define ll long long


int main() {
    int tc = 1;
    for(int t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);

        for(auto &v: arr) cin >> v;
        vector<ll> prefixSum;
        prefixSum.push_back(0);

        ll sum = 0;
        for(auto v: arr) {
            sum += v;
            prefixSum.push_back(v);
        }


        ll ans = 0;
        for(int i = 1; i <= arr.size(); i++) {
            unordered_set<ll> st;
            for(int j = 0; j < arr.size(); j+=i) {
                ll sum = arr[j] - arr[j-i-1];
                st.insert(sum);
            }

            if(st.size() == 1) {
                ans = i;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
