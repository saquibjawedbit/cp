#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n, k; cin >> n >> k;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;
        vector<ll> maxSteps(k+1, 0), lastStep(k+1, 0), secondMaxSteps(k+1, 0);
        for(int i = 0; i < arr.size(); i++) {
            ll jump = i- lastStep[arr[i]];
            if(jump >= maxSteps[arr[i]]) {
                secondMaxSteps[arr[i]] = maxSteps[arr[i]];
                maxSteps[arr[i]] = jump;
            }
            else {
                secondMaxSteps[arr[i]] = max(secondMaxSteps[arr[i]], jump);
            }

            lastStep[arr[i]] = i+1;
        }




        ll ans = INT_MAX;

        for(int i =1; i <= k; i++) {
            ll jump = n - lastStep[i];
            if(jump >= maxSteps[i]) {
                secondMaxSteps[i] = maxSteps[i];
                maxSteps[i] = jump;
            }
            else {
                secondMaxSteps[i] = max(secondMaxSteps[i], jump);
            }
            //cout << i  << " " << maxSteps[i] << " " << secondMaxSteps[i] << endl;
            ans = min(ans, max(secondMaxSteps[i], maxSteps[i]/2));
        }

        cout << ans << endl;
    }
} 