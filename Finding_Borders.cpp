#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9+7;

vector<ll> calcHash(string &s) {
    vector<ll> hashVal;
    ll hash = 0;
    hashVal.push_back(0);
    for(auto v: s) {
        hash = ((hash * 31) % MOD + (v-'a'+1)) % MOD;
        hashVal.push_back(hash);
    }

    return hashVal;
}

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


ll getHash(vector<ll> &hashes, ll left, ll right) {
    ll res = (hashes[right+1] - (hashes[left] * modular_pow(31, right-left+1, MOD)) % MOD + MOD) % MOD;
    return res;
}


int main() {
    string s; cin >> s;

    char st = s[0], end = s[s.size()-1];

    vector<ll> hashes;
    hashes = calcHash(s);

    // for(auto v: hashes) cout << v << " ";
    // cout << endl;

    // cout << getHash(hashes, 8, 9) << endl;



    ll left = INT_MIN, right = INT_MIN;
    for(int i = 0; i < s.size()-1; i++) {
        // cout << 
        // cout << getHash(hashes, 0, i) << " " << getHash(hashes, s.size()-i-1, s.size()-1) << endl;
        if(getHash(hashes, 0, i) == getHash(hashes, s.size()-i-1, s.size()-1)) {
            cout << i+1 << " ";
        }
    }
    cout << endl;

    return 0;
}