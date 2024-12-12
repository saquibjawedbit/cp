#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main()
{
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<ll> pre;
        ll sum = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '1') {
                sum++;
            }
            else {
                sum--;
            }
            pre.push_back(sum);
        }

        // for(auto v: pre) cout << v << " ";
        // cout << endl;

        pre[pre.size()-1] = 0;
        sort(pre.begin(), pre.end(), greater<ll>());

        ll ans = 1;
        sum = 0;
        for(auto v: pre) {
            ans++; sum += v;
            if(sum >= k) {
                break;
            }
        }

        if(sum >= k) cout << ans << endl;
        else cout << -1 << endl;
    }
}