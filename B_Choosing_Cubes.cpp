#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll tc = 0; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        int n, f, k; cin >> n >> f >> k;
        vector<ll> arr(n, 0);
        for(int i = 0; i < n; i++) cin >> arr[i];

        int key = arr[f-1];   
        sort(arr.begin(), arr.end(), greater<int>());

        int currIndex = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] == key) {
                currIndex = i;
                break;
            }
        }
        k--;        

        int endIndex = currIndex;
        while(endIndex < n && arr[endIndex] == key) {
            endIndex++;
        }
        if(endIndex != currIndex) endIndex--;

        //cout << currIndex << " " << endIndex << endl;

        if(k >= endIndex) cout << "YES" << endl;
        else if(k >= currIndex && k <= endIndex) cout << "MAYBE" << endl;
        else cout << "NO" << endl;
    }
}