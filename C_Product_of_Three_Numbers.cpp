#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

void solve(ll n, ll start, vector<ll> &ans) {
    if(n <= 1 || ans.size() >= 3) return;

    for(ll i = start; i <= sqrt(n); i++) {
        if((n % i) == 0) {
            ll maxi = max(i , n/i);
            ll mini = min(i, n/i);
            if(ans.size() == 0) {
                ans.push_back(mini);
                solve(maxi, i+1, ans);
                return;
            }
            else if(maxi != mini) {
                
                ans.push_back(mini);
                ans.push_back(maxi);
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> ans;
        solve(n, 2, ans);
        if(ans.size() == 3) {
            cout << "YES" << endl;
            for(auto v: ans) cout << v << " ";
            cout << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
} 
