#include <bits/stdc++.h>

using namespace std;

#define ll long long

using namespace std;

int main() {
    int tc; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        int n; cin >> n;
        set<int> arr;
        for(int i = 0; i < n; i++) {
            int val; 
            cin >> val; 
            arr.insert(val);
        }

        bool alice = 1;
        ll acc = 0;
        for(auto v: arr) {
            ll trueValue = v - acc;
            alice = !alice;
        
            if(trueValue != 1) break;
            acc += trueValue;
        }

        if(alice) cout << "Bob" << endl;
        else cout << "Alice" << endl;


    }
}