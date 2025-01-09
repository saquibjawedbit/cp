#include <bits/stdc++.h>


using namespace std;

#define ll long long
#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);  // Disable sync with C I/O
    cin.tie(nullptr); 
    cout.tie(nullptr);
    ll tc = 1;
    cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll m, n;
        cin >> m >> n;
        vector<vector<ll>> arr(m, vector<ll>(n));

        for(auto &n: arr) {
            for(auto &v: n) cin >> v;
        }

        auto check = [&](ll mid) {
            set<ll> s;
            ll cnt = 0;
            for(int i = 0; i < n; i++) {
                ll prevSize = s.size();
                bool found = false; ll nCnt = 0;
                for(int j = 0; j < m; j++) {
                    if(arr[j][i] >= mid) {
                        s.insert(j);
                        nCnt++;
                        found = true;
                    }
                }

                if(!found) return false;
                
                ll del = s.size() - prevSize;

                if(del == nCnt) cnt++;
            }

            if(cnt <= n-1) return true;
            else return false;
        };
        
        //Hello
        ll left = 0, right = 1e9;
        ll ans = 0;
        while(right >= left) {  
            ll mid = left + (right - left)/2;
            if(check(mid)) {
                left = mid + 1;
                ans = mid;
            }
            else {
                right = mid - 1;
            }
        }
        cout << ans << endl;
       
    }
}