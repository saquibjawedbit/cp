#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll n; scanf("%lld", &n);
    ll *arr = new ll[n];
    for(int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }


    map<ll, ll> mp;
    vector<pair<ll,ll>> ans;
    ll left = 1;
    for(int i = 0; i < n; i++) {
        if(mp.find(arr[i]) != mp.end()) {
            ans.push_back({left, i + 1});
            left = i + 2;
            mp.clear();
        }
        else {
            mp[arr[i]] = 1;
        }
    }

    if(ans.empty()) {
        cout << -1 << endl;
        return 0;
    }

    // ll last = max(ans.back().second, (ll) ans.size());
    ans[ans.size()-1].second = n;

    ll len = ans.size();
    printf("%lld\n", len);
    for(auto v: ans) {
        printf("%lld %lld\n", v.first, v.second);
    }
}