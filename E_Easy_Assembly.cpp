#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll n; cin >> n;
    vector<ll> arr;
    vector<vector<ll>> mp(n);
    for(int i = 0; i < n; i++) {
        ll k; cin >> k;
        while(k-- > 0) {
            ll d; cin >> d;
            arr.push_back(d);
            mp[i].push_back(d);
        }
    }

    sort(arr.begin(), arr.end());

    ll split = 0, combine = n-1;

    for(auto &nArr: mp) {
        for(int i = 0; i < nArr.size(); i++) {
            ll index = lower_bound(arr.begin(), arr.end(), nArr[i]) - arr.begin();
            if(i+1 < nArr.size() && index+1 < arr.size() && nArr[i+1] != arr[index+1]) {
                split++;
            }
            else if(i+1 < nArr.size() && index+1 >= arr.size()) {
                split++;
            }
        }
    }
    combine += split;

    cout << split << " " << combine << endl;


}