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
        ll n, k; cin >> n >> k;
        vector<string> arr(n-k+1);

        for(auto &v: arr) cin >> v;

        vector<string> names;
        string sName = "A";

        for(int i = 0; i < n; i++) {
            names.push_back(sName);
            sName.back()++;

            if(sName.back() == 'z'+1 || sName.back() == 'Z'+1) {
                sName.back()--;
                sName.push_back('a');
            }
        }



        //8-3 = 5
        for(int i = 0; i < n-k+1; i++) {
            // cout << i << endl;
            if(arr[i] == "NO") {
                names[i+k-1] = names[i];
            }
        }

        for(auto v: names) cout << v << " ";
        cout << endl;

        
    }
}