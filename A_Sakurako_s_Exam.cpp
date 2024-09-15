#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

bool solve(vector<ll> &arr, int index, int sum) {
    if(index >= arr.size()) {
        if(sum == 0) return true;
        else return false;
    }

    bool pos = solve(arr, index+1, arr[index]+sum);
    if(pos) return true;
    bool neg = solve(arr, index+1, sum - arr[index]);
    return neg;
}



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll a, b; cin >> a >> b;
        vector<ll> arr;
        while(a-- > 0) arr.push_back(1);
        while(b--  > 0) arr.push_back(2);


        bool ans = solve(arr, 0, 0);
        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
} 