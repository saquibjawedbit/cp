#include <bits/stdc++.h>

#define ll long long

using namespace std;

int gcd(int a, int b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
} 
  
// Function to find gcd of array of 
// numbers 
int findGCD(vector<ll> &arr, int n) 
{ 
  int result = arr[0]; 
  for (int i = 1; i < n; i++) 
  { 
    result = gcd(arr[i], result); 
  
    if(result == 1) 
    { 
    return 1; 
    } 
  } 
  return result; 
} 

int main() {
    ll tc = 0; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll n; cin >> n;
        vector<int> v(n, 0);
        for(ll i = 0; i < n; i++) cin >> v[i];

        sort(v.begin(), v.end());

        vector<ll> ls;
        for(ll i = 1; i < n; i++) {
            ll diff = abs(v[i] - v[i-1]);
            ls.push_back(diff);
        }
        
        ll step = 1;

        if(ls.size() != 0) {
           // sort(ls.begin(), ls.end());
            step = findGCD(ls, ls.size());
        }
        
        ll ans = 0, maxi = v[n-1];
        bool isReset = false;
        for(ll i = 0; i < n; i++) {
            ll temp = (maxi - v[i])/step;
            ll ns = temp * step + v[i];
            ans += temp;
            if(maxi != ns) {
                maxi += step;
                i = -1;
                ans = 0;
                isReset = true;
            }
        }

        if(!isReset) {
            ll next1 = maxi;
            ll i = n-1;
            for(; i >= 0; i--) {
                if(v[i] == next1) {
                    next1 -= step;
                }
                else {
                    ans += (n-i-1);
                    break;
                }
            }
            if(i == -1) {
                ans += n;
            }
        }

        cout << ans << endl;
    }
}