#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

bool isSorted(string s, vector<int> &arr) {
    if(arr.size()== 0) return true;
    ll left = 0, right = arr.size()-1;
    while(right >= left) {
        swap(s[arr[left]], s[arr[right]]);
        left++; right--;
    }
    
    for(ll i = 1; i < s.size(); i++) {
        if(s[i] < s[i-1]) return false; 
    }
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        string s; cin >> s;
        vector<int> arr;
        for(ll i = 0; i < n; i++) {
            if(arr.size() == 0) {
                arr.push_back(i);
                continue;
            }

            while(!arr.empty() && s[arr[arr.size()-1]] < s[i]) {
                arr.pop_back(); 
            }
            arr.push_back(i);
        }
        bool sorted = isSorted(s, arr);


        ll counter = 0;
        if(!arr.empty()) {
            char maxi = s[arr[0]];
            for(int i = 0; i < arr.size(); i++) {
                if(s[arr[i]] == maxi) counter++;
                else break;
            }
        }


        if(!sorted) cout << -1 << endl;
        else cout << (arr.size()-counter) << endl;

    }


}