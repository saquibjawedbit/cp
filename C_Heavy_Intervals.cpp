#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<pair<ll, int>> arr(2 * n);
        vector<ll> c(n);
        for(int i = 0; i < n ; i++) cin >> arr[i].first, arr[i].second = 1;
        for(int i = n; i < 2*n; i++) cin >> arr[i].first, arr[i].second = 2;
        for(auto &v: c) cin >> v;


        sort(arr.begin(), arr.end(), greater<pair<ll, int>>());
        sort(c.begin(), c.end(), greater<ll>());
        stack<ll> st;
        vector<ll> nArray;
        ll ans = 0;
        for(ll i = 0; i < (2 * n); i++) {
            if(arr[i].second == 2) st.push(arr[i].first);
            else {
                ll top = st.top() - arr[i].first;
                nArray.push_back(top);
                st.pop();
            }
        }

        sort(nArray.begin(), nArray.end());

        for(ll i = 0; i < n; i++) {
            ans += nArray[i] * c[i];
        }

        cout << ans << endl;
    }
}