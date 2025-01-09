#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);  // Disable sync with C I/O
    cin.tie(nullptr); 
    cout.tie(nullptr);
    ll tc = 1;
    // cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        vector<vector<ll>> nArr(n);

        for(int i = 0; i < n; i++) {
            ll left = 0, right = n-1;
            ll ans = 0;
            while(right >= left) {
                ll mid = left + (right - left) / 2;
                if(nArr[mid].empty() || nArr[mid].back() <= arr[i]) {
                    right = mid -1;
                    ans = mid;
                } else {
                    left = mid + 1;
                }
            }
            nArr[ans].push_back(arr[i]);
        }

        for(int i = 0; i < nArr.size(); i++) {
            if(nArr.empty()) break;
            for(auto &v: nArr[i]) cout << v << " ";
            cout << endl;
        }


    }
}