#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'


ll query(ll index) {
    cout << "? " << index  << endl;
    ll x; cin >> x;
    return x;
}

int main() {

    // ios_base::sync_with_stdio(false);  // Disable sync with C I/O
    // cin.tie(nullptr); 
    // cout.tie(nullptr);
    ll tc = 1;
    cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n; cin >> n;

        vector<ll> arr(n+1, -1);
        for(int i = 1; i <= n; i++) {
            if(arr[i] == -1) {
                ll target = query(i);
                ll curr = query(i);
                vector<ll> cycle;
                cycle.push_back(curr);
                while(curr != target) {
                    curr = query(i);
                    cycle.push_back(curr);
                }

                for(int j = 0; j < cycle.size(); j++) {
                    arr[cycle[j]] = cycle[(j+1) % cycle.size()];
                }
            }
        
        }

        cout << "! ";
        for(int i = 1; i < arr.size(); i++) cout << arr[i] << " ";
        cout << endl;
    }
}