#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);  // Disable sync with C I/O
    cin.tie(nullptr); 
    cout.tie(nullptr);
    ll tc = 1;
    // cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n;
        cin >> n;
        string a, b; cin >> a >> b;

        ll aOnes = 0, bOnes =0;
        ll common = 0;

        for(int i = 0; i < a.size(); i++) {
            if(a[i] == '1' && b[i] == '1') common++;
            else if(b[i] == '1') bOnes++;
            else if(a[i] == '1') aOnes++;
        }

        if(common % 2 == 1) {
            aOnes += (common)/2 + 1;
            bOnes += (common)/2;
        }
        else {
            aOnes += (common)/2;
            bOnes += (common)/2;
        }

        // ll nA = 0, nB = 0;

        // if(bOnes > aOnes) {
        //     ll delta = bOnes - aOnes;
        //     aOnes -=  (delta)/2;
        // }
        // else {
        //     ll delta = aOnes - bOnes;
        //     bOnes -= (delta)/2;
        // }

        // cout << aOnes << " " << bOnes << endl;


        if(aOnes == bOnes || aOnes+1 == bOnes) cout << "Draw" << endl;
        else if(aOnes > bOnes) cout << "First" << endl;
        else cout << "Second" << endl;
       
    }
}