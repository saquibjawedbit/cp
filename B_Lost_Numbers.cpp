#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<ll> arr = {42, 23, 16, 15, 8, 4};

    map<ll, pair<ll,ll>> mp;
    for(int i =0; i < arr.size(); i++) {
        for(int j = i+1; j < arr.size(); j++) {
            ll prod = arr[i] * arr[j];
            mp[prod] = {arr[i], arr[j]};
        }
    }

    vector<ll> ans(6, 0);
  
        cout << "? " << (1) << " " << (2) << endl;
        ll s1; cin >> s1;
        cout << "? " << (2) << " " << (3) << endl;
        ll s2; cin >> s2;

        pair<ll, ll> f1 = mp[s1];
        pair<ll,ll> f2 = mp[s2];

        if(f1.first == f2.first) {
            ans[1] = f1.first;
            ans[0] = f1.second;
            ans[2] = f2.second; 
        }
        else if(f1.first == f2.second) {
            ans[1] = f1.first;
            ans[0] = f1.second;
            ans[2] = f2.first; 
        }
        else if(f1.second == f2.second) {
            ans[1] = f1.second;
            ans[0] = f1.first;
            ans[2] = f2.first; 
        }
        else if(f1.second == f2.first) {
            ans[1] = f1.second;
            ans[0] = f1.first;
            ans[2] = f2.second; 
        }

        cout << "? " << 4 << " " << 5 << endl;
        s1; cin >> s1;
        cout << "? " << 5 << " " << 6 << endl;
        s2; cin >> s2;

        f1 = mp[s1];
        f2 = mp[s2];

        if(f1.first == f2.first) {
            ans[4] = f1.first;
            ans[3] = f1.second;
            ans[5] = f2.second; 
        }
        else if(f1.first == f2.second) {
            ans[4] = f1.first;
            ans[3] = f1.second;
            ans[5] = f2.first; 
        }
        else if(f1.second == f2.second) {
            ans[4] = f1.second;
            ans[3] = f1.first;
            ans[5] = f2.first; 
        }
        else if(f1.second == f2.first) {
            ans[4] = f1.second;
            ans[3] = f1.first;
            ans[5] = f2.second; 
        }


    cout << "! ";
    for(auto v: ans) cout << v << " ";
    cout << endl;



}