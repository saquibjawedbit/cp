#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    //cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n, k; cin >> n >> k;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        queue<ll> q;
        double sum  = 0, temp = 0;
        for(int i = 0; i < n; i++) {
            if(q.size() != k) {
                temp += arr[i];
                q.push(arr[i]);
            }
            else {
                sum += temp;
                temp -= q.front();
                q.pop();
                temp += arr[i];
                q.push(arr[i]);
            }
        }

        sum += temp;

        double ans = (sum)/(n-k+1);

       cout << fixed << setprecision(10) << ans << endl;
        
    }
} 
