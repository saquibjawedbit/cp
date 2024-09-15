#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        ll n, m; cin >> n >> m;
        vector<ll> arr(m);
        for(auto &v: arr) cin >> v;

        sort(arr.begin(), arr.end());

        //Delta
        vector<ll> diff;
        ll ans = m;
        for(int i = 1; i < m; i++) {
            ll temp = arr[i] - arr[i-1] - 1;
            diff.push_back(temp); 
        }

        ll protected_house = 0, delta = 0;
        if(arr.size() > 1) {
            ll ini = arr[0] -1 + n - (arr[arr.size()-1]);
            diff.push_back(ini);
        }
        else {
            protected_house = n-2;
        }

        sort(diff.begin(), diff.end());

        while(!diff.empty()) {
            if(diff[diff.size()-1] - delta > 0) {
                if((diff[diff.size()-1]-delta) == 1) {
                    protected_house += 1;
                    delta += 2;
                }
                else {
                    protected_house += diff[diff.size()-1] - delta - 1;
                    delta += 4;
                }
                diff.pop_back();
            }
            else {
                break;
            }
        }

        ans = n - protected_house;
        cout << ans << endl;

    }
}