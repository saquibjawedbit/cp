#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;

        ll yassir = 0, adele = 0;
        vector<ll> sum;

        sum.push_back(0);
        for(int i = 0; i < n; i++) {
            sum.push_back(sum[sum.size()-1] + arr[i]);
            yassir += arr[i];
        }

        deque<ll> mini;
        mini.push_back(0);
        for(int i = 1; i < sum.size(); i++) {

            if(i - mini.front() == (n)) {
                mini.pop_front();
            }

            adele = max(adele, sum[i] - sum[mini.front()]);

            while(!mini.empty() && sum[mini.back()] > sum[i]) {
                mini.pop_back();
            }

            mini.push_back(i);
        }

        //cout << adele << endl;



        if(adele >= yassir) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
        
    }
} 
