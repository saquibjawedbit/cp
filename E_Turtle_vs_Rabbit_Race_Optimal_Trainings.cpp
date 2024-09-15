#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

ll solve(vector<ll> &arr, vector<ll> &prefix, ll l, ll u) {
    ll left = l -1, right = arr.size()-1;
    ll ans = l;
    while(right >= left) {
        ll mid = left + (right - left)/2;
        if((prefix[mid+1]-prefix[l-1]) <= u) {
            left = mid + 1;
            ans = mid+1;
        }
        else {
            ll leftPoint = u - (prefix[mid] - prefix[l-1]);
            if(leftPoint > 0) {
                ll sum1 = leftPoint * (leftPoint+1)/2;
                ll d = (arr[mid]-leftPoint-1);
                ll sum2 = d * (d+1)/2;
                if(sum1 > sum2) {
                    return mid+1;
                }
            }
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto& v: arr) cin >> v;
        vector<ll> prefix; ll sum = 0;
        prefix.push_back(0);
        for(auto v: arr) {
            sum += v;
            prefix.push_back(sum);
        }   
        ll q; cin >> q;
        while(q-- > 0) {
            ll l, u; cin >> l >> u;
            cout << solve(arr, prefix, l , u) << " ";
        }
        cout << endl;
    }
}