#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    //cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        int n, k; cin >> n >> k;
        while(k-- > 0) {
            int digit = n % 10;
            if(digit == 0) n /= 10;
            else n--;
        }
        cout << n << endl;
    }
} 