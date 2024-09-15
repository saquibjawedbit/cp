#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(ll i = 0; i < n; i++) cin >> arr[i];
        priority_queue<ll> pq;
        pq.push(0);
        ll prevSum = arr[0];
        pq.push(arr[0]);
        ll ans = 0;
        if(arr[0] == 0) ans = 1;
        for(ll i = 1; i < n; i++) {
            ll temp = prevSum - pq.top();
            if(arr[i] == prevSum || (arr[i]+temp) == pq.top()) ans++;

            prevSum += arr[i];
            pq.push(arr[i]);
        }

        cout << ans << endl;
       
    }
}