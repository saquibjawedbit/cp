#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc = 0; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        int mask = 0;
        for(int i = 0; i < n; i++) mask |= v[i];

        int windowSize = 1, nMask = 0;
        for(int i = 0; i < n; i++) {
            nMask |= v[i];
            if(nMask == mask) {
                break;
            }
            else {
                windowSize++;
            }
        }

        for(int i = 0; i < n-windowSize+1; i++) {
            nMask = 0;
            for(int j = i; j < i+windowSize; j++) {
                nMask |= v[j];
            }
            if(nMask != mask) {
                windowSize++;
                i--;
            }
        }
        cout << windowSize << endl;
    }
}