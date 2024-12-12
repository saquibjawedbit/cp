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