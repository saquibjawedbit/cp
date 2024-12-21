#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> arr(n);
    for(auto &v: arr) cin >> v;

    vector<ll> nArr;
    for(int i = 1; i < arr.size(); i++) {
        nArr.push_back(arr[i] - arr[i-1]-1);
    }

    sort(nArr.begin(), nArr.end());

    ll ans = arr[arr.size()-1] - arr[0] + 1;

    if(k == 1) {
        cout << ans << endl;
        return 0;
    }

    for(ll i = 2; i <= k; i++) {
        if(nArr.empty()) break;
        ans -= nArr[nArr.size()-1];
        ans = min(ans, ans);
        nArr.pop_back();
    }

    cout << ans << endl;


}