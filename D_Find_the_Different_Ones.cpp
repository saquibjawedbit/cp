#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i++) cin >> arr[i];
    
    vector<int> diff;
    for(int i = 0; i < n-1; i++) {
        if(arr[i] != arr[i+1]) diff.push_back(i);
    }

    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        a--; b--;

        int start = 0, end = diff.size()-1;
        bool found = false;
        while(end >= start) {
            int mid = end + (start - end)/2;
            if(diff[mid] >= a && diff[mid] < b) {
                cout << diff[mid]+1 << " " << diff[mid] + 2 << endl;
                found = true;
                break;
            }
            else if(diff[mid] >= a && diff[mid] >= b) end = mid -1;
            else if(diff[mid] < a) start = mid +1;
        }
        if(!found) cout << "-1 -1" << endl;
    }

    cout << endl;
}


int main() {
    int t; cin >> t;
    while(t-- > 0) solve();
}