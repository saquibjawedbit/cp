#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    int tc= 1;
    cin >> tc;
    for(int t =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<char> arr = {'a', 'e', 'i', 'o', 'u'};

        string ans = "";
        ll common = (n/5);
        ll extra = n % 5;
        if(extra != 0) common++;
        ll index = 0;
        while(n > 0) {
            if(extra > 0) {
                for(int i = 0; i < common; i++) {
                    ans.push_back(arr[index]);
                    n--;
                }
                extra--;
                if(extra == 0) {
                    common--;
                }
            }
            else {
                for(int i = 0; i < common; i++) {
                    ans.push_back(arr[index]);
                    n--;
                }
            }
            index = (index + 1) % 5;
        }
        cout << ans << endl;

    } 

}