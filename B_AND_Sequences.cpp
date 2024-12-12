#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9+7;

void compute(vector<ll> &fact) {
    fact[0] = 1;
    for(ll i = 1; i < 2e5+1; i++) {
        fact[i] = (i * fact[i-1]) % MOD; 
    }
}


ll power(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}


int main() {

    vector<ll> fact(2e5+1, 0);

    compute(fact);
    ll modInverse2 = power(2, MOD-2, MOD); // Compute modular inverse of 2
    ll tc = 1; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);

        for(auto &v: arr) cin >> v;

        sort(arr.begin(), arr.end());

        swap(arr[1], arr[arr.size()-1]);

        vector<ll> pre(n, 0);
        ll res = INT_MAX;
        for(ll i = n-1; i >= 0; i--) {
            res = res & arr[i];
            pre[i] = res;
        }


        ll nRes = INT_MAX, freq = 1;

        for(int i = 0; i < n-1; i++) {
            nRes = nRes & arr[i];
            if(nRes != pre[i+1]) {
                freq = -1;
                break;
            }

            if(arr[i] == res) freq++;
        } 

        if(freq == -1) {
            cout << 0 << endl;
            continue;
        }
        ll ans = (2 * (fact[n-2] * ((freq * (freq-1)) % MOD) % MOD) * modInverse2) % MOD;



        // cout << (freq * (freq -1))/2 << endl;


        cout << ans << endl;
    }
}