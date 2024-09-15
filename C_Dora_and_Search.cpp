#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ll tc = 1; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        if(n <= 2) {
            cout << -1 << endl;
            continue;
        }
        
        ll mini = 1, maxi = n;

        ll l = 0, r = n-1;


        while(r > l) {
            if(mini == arr[l]) {
                l++;
                mini++;
                continue;
            } 
            else if(mini == arr[r]) {
                r--;
                mini++;
                continue;
            }
            else if(maxi == arr[l]) {
                l++;
                maxi--;
                continue;
            }
            else if(maxi == arr[r]) {
                r--;
                maxi--;
                continue;
            }
            
            break;
        }
        if(l == r) cout << -1 << endl;
        else cout << l+1 << " " << r+1 << endl;
    }
}