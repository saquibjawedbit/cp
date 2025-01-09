#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, k; 
    cin >> n >> k;
    vector<ll> arr(n);
    for(auto &v: arr) cin >> v;

    vector<ll> compressed;
    for(int i = 0; i < n; i++) {
        if(compressed.empty() || arr[i] != compressed.back()) {
            compressed.push_back(arr[i]);
        }
    }

    vector<ll> stress(k + 1, 0);
    stress[compressed[0]]++;  // First genre stress
    stress[compressed.back()]++;  // Last genre stress

    // Middle stress points
    for(int i = 1; i < compressed.size() - 1; i++) {
        if(compressed[i-1] != compressed[i+1]) {
            stress[compressed[i]]++;
        }
        else {
            stress[compressed[i]] += 2;
        }
    }

    // Find genre with max stress
    ll ans = 1;
    for(int i = 2; i <= k; i++) {
        if(stress[i] > stress[ans]) {
            ans = i;
        }
    }

    cout << ans << endl;
    return 0;
}