#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

ll getVal(vector<vector<int>> &nMap, ll mid, ll l) {
    ll value = 0;
    for(int i = 0; i < 64; i++) {
        if((nMap[mid][i] - nMap[l][i]) >= (mid - (l))) value += (1ll << (i));
    }
    return value;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tc = 1; cin >> tc;
    for (ll t1 = 1; t1 <= tc; t1++) {
        ll n; cin >> n;
        vector<ll> arr(n);

        for(auto &v: arr) cin >> v;
        ll val = 0;
        
        vector<vector<int>> nMap(n+1, vector<int>(64, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 64; j++) {
                ll bit = arr[i-1] & (1ll << j);
                if(bit != 0) nMap[i][j] += (nMap[i-1][j] + 1);
                else nMap[i][j] = nMap[i-1][j];
            }
        }

        ll q; cin >> q;
        while(q-- > 0) {
            ll l, k; cin >> l >> k;

            l = l-1;
            ll left = l, right = n-1;
            ll ans = -1;
            while(right >= left) {
                ll mid = left + ((right - left) >> 1ll);
                if(getVal(nMap, mid+1, l) >= k) {
                    left = mid + 1;
                    ans = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            } 
            cout << ans << " ";
        } cout << endl;

        //cout << getVal(nMap, 3,2);

    }
}