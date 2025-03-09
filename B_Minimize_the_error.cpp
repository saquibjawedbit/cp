#include <bits/stdc++.h>

using namespace std;

#define ll long long



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1; //cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n, k1, k2; cin >> n >> k1 >> k2;
        vector<ll> a(n), b(n);
        for(auto &v: a) cin >> v;
        for(auto &v: b) cin >> v;

        priority_queue<pair<ll,ll>> maxHeap;

        for(int i = 0; i < n; i++) {
            maxHeap.push({abs(a[i] - b[i]), i});
        }

        while(maxHeap.top().first != 0 && (k1 > 0 || k2 > 0)) {
            ll index = maxHeap.top().second;
            ll currDiff = maxHeap.top().first;
            maxHeap.pop();

            ll target = max(maxHeap.top().first-1,0ll);

            if(a[index] < b[index]) {
                ll req = b[index] - target - a[index];
                if(k1 >= req) {
                    a[index] += req;
                    k1 -= req;
                    maxHeap.push({target, index});
                } 
                else {
                    a[index] += k1;
                    req -= k1;
                    k1 = 0;
                    
                    if(k2 >= req) {
                        b[index] -= req;
                        k2 -= req;
                        maxHeap.push({target, index});
                    }
                    else {
                        b[index] -= k2;
                        req -= k2;
                        k2 = 0;
                    }
                }
            }
            else {
                ll req = a[index] - target - b[index];
                if(k1 >= req) {
                    a[index] -= req;
                    k1 -= req;
                    maxHeap.push({target, index});
                } 
                else {
                    a[index] -= k1;
                    req -= k1;
                    k1 = 0;
                    
                    if(k2 >= req) {
                        b[index] += req;
                        k2 -= req;
                        maxHeap.push({target, index});
                    }
                    else {
                        b[index] += k2;
                        req -= k2;
                        k2 = 0;
                    }
                }
            }
        }

        ll leftOut = max(k1, k2) - min(k1, k2);

        ll ans = 0;
        if(leftOut&1) ans++;
        for(int i = 0; i < n; i++) {
            ans += (b[i] - a[i]) * (b[i] - a[i]);
        }

        cout << ans << endl;
    }
}