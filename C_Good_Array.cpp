#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    //cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<pair<ll,ll>> arr(n);
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i].first;
            arr[i].second = i+1;
            sum += arr[i].first;
        }

        sort(arr.begin(), arr.end());

        vector<ll> ans;
        for(int i = 0; i < n; i++) {
            if(i != (arr.size()-1)) {
                ll rem = sum - arr[i].first - arr[arr.size()-1].first;
                if(rem == arr[arr.size()-1].first) {
                    ans.push_back(arr[i].second);
                } 
            }
            else {
                ll rem = sum - arr[i].first - arr[arr.size()-2].first;
                if(rem == arr[arr.size()-2].first) {
                    ans.push_back(arr[i].second);
                }
            }
        } 

        cout << ans.size() << endl;
        for(auto v: ans) cout << v << " ";
        cout << endl;
        
    }
} 
