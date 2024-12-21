#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
       ll n; cin >> n;
       vector<ll> arr(n);
       for(auto &v: arr) cin >> v;

       if(arr.size() <= 2) {
            for(auto v: arr) cout << v << " ";
            cout << endl;
            continue;
       }


        vector<ll> isPresent(n+2, 0);
        for(auto v: arr) isPresent[v] = 1;

        ll index = 1;

        map<ll, ll> freq;
        for(int i = 0; i < arr.size(); i++) {
            while(isPresent[index]) index++;

            if(freq[arr[i]] == 0) {
                freq[arr[i]]++;
            }
            else {
                arr[i] = index;
                isPresent[index] = 1;
            }

        }

        for(auto v: arr) cout << v << " ";
        cout << endl;
    }
}