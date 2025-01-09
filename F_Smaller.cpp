#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tc = 1; cin >> tc;
    for(ll t1 = 1; t1 <= tc; t1++) {
        ll q; cin >> q;

        char s = 'a', t = 'a';
        ll ls = 0, lt = 0;
        vector<ll> maxS(26, 0);
        vector<ll> maxT(26, 0);


        while(q-- > 0) {
            ll d, k; cin >> d >> k;
            string a; cin >> a;

            if(d == 1) {
                for(auto v: a) {
                    maxS[v-'a']+=k;
                }
                s = max(*max_element(a.begin(), a.end()), s);
                ls += (a.size() * k);
            }   
            else {
                for(auto v: a) {
                    maxT[v-'a']+=k;
                }
                t = max(*max_element(a.begin(), a.end()), t);
                lt += (a.size() * k);
            }

            ll delta = ls - lt;

            if((s == t && ls < lt) || (s == t && ls > lt && maxS[s-'a'] <= delta ||  (s == t && ls == lt && maxS[s-'a'] < maxT[t-'a']))  || (s < t)) {
                cout << "YES" << endl;
            } 
            else {
                cout << "NO" << endl;
            }
        }
    }
}