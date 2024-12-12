#include <bits/stdc++.h>

using namespace std;

#define ll long long


const ll MOD = 1e9+7;
const ll MOD2 = 1e9+9;

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


void calcHash(string &s, vector<pair<ll,ll>> &hash) {
    ll sum = 0;
    ll sum2 = 0;
    hash.push_back({0,0});
    for(auto v: s) {
        sum = ((sum * 31) % MOD + (v-'a'+1)) % MOD;
        sum2 = ((sum2 * 53) % MOD2 + (v-'a'+1)) % MOD2;
        hash.push_back({sum, sum2});
    }
}

pair<ll,ll> getHash(vector<pair<ll, ll>> &hash, ll left, ll right) {
    ll value1 = (hash[right+1].first  - (hash[left].first * modular_pow(31, right-left+1,MOD)) % MOD + MOD) % MOD;
    ll value2 = (hash[right+1].second  - (hash[left].second * modular_pow(53, right-left+1,MOD2)) % MOD2 + MOD2) % MOD2;
    return {value1, value2};
}

// Custom hash function for pair<long long, long long>
struct pair_hash {
    template <typename T1, typename T2>
    size_t operator ( )(const pair<T1, T2> &p) const {
        size_t h1 = hash<T1>{}(p.first);
        size_t h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);  // Combine the two hash values
    }
};


int main() {
    string s, c; cin >> s >> c;
    ll k; cin >> k;
    
    vector<pair<ll, ll>> hashVal;

    calcHash(s, hashVal);

    ll ans = 0;
    unordered_set<pair<ll, ll>, pair_hash> isVisited; 
    for(int i = 0; i < s.size(); i++) {
        ll cnt = 0;
        for(int j = i; j < s.size(); j++) {
            if(c[s[j] - 'a'] == '0') cnt++;

            if(k < cnt) {
                break;
            }
            else {
                pair<ll, ll> hash = getHash(hashVal, i, j);
                if(isVisited.find(hash) == isVisited.end()) {
                    ans++; isVisited.insert(hash);
                }
            }
        }
        // cout << i << " " << ans << endl;
    }

    cout << ans << endl;

    return 0;
}