#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9+7;

long long modular_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod; // Ensure base is within mod
    
    while (exp > 0) {
        if (exp % 2 == 1) { // If exp is odd
            result = (result * base) % mod;
        }
        base = (base * base) % mod; // Square the base
        exp /= 2; // Halve the exponent
    }
    return result;
}


void calcHash(string &s, vector<ll> &hash) {
    ll sum = 0;
    hash.push_back(0);
    for(auto v: s) {
        sum = ((sum * 31) % MOD + (v-'a'+1)) % MOD;
        hash.push_back(sum);
    }
}

ll getHash(vector<ll> &hash, ll left, ll right) {
    ll value = (hash[right+1]  - (hash[left] * modular_pow(31, right-left+1,MOD)) % MOD + MOD) % MOD;
    return value;
}

bool isValid(vector<ll> &hash, ll len, ll n) {
    ll left = getHash(hash, 0, len-1);
    for(ll j = 1; j < n-1; j++) {
        if((j+len-1) >= n-1) break;
        if(left == getHash(hash, j, j + len-1)) {
                return true;
        }
    }
    return false;
}



int main() {
    ll tc = 1;
    for(ll t =1; t <= tc; t++) {
        string s; cin >> s;
        vector<ll> hash;
        calcHash(s, hash);

        // cout << isValid(hash, 1, s.size()) << endl;
        ll ans = -1;

        vector<ll> val;
        for(int i = 0; i < s.size(); i++) {
            ll left = getHash(hash, 0, i);
            ll right = getHash(hash, s.size()-i-1, s.size()-1);
            if(left == right) val.push_back(i+1);
        }


        ll left = 0, right = val.size()-1;
        while(right >= left) {
            ll mid = left + (right - left)/2;
            if(isValid(hash, val[mid], s.size())) {
                ans = val[mid];
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }

        if(ans == -1) cout << "Just a legend" << endl;
        else cout << s.substr(0, ans) << endl;

    }
}