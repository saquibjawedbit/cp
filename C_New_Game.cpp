#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
    cin >> tc;
    for (ll t1 = 1; t1 <= tc; t1++)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        for (auto &v : arr)
            cin >> v;

        map<ll, ll> mp;

        for (auto v : arr)
            mp[v]++;
        ll ans = 0, temp = 0;
        deque<ll> q;
        for (auto v : mp)
        {
            // cout << v.first << " " << v.second << endl;
            
            if(q.size() >= k) {
                temp -= mp[q.front()];
                q.pop_front();
            }
            //if(!q.empty()) cout << q.back() << " " << v.first << " " << (!q.empty() && (q.back() == (v.first + 1))) <<  endl;
            if (q.empty() || (q.back() == v.first) || (q.back() == (v.first - 1ll)))
            {
                //cout << v.first << endl;
                temp = temp;
            }
            else
            {
                // cout << "NO!" << endl;
                temp = 0;
                q.clear();
            }
            temp += v.second;
            ans = max(ans, temp);
            q.push_back(v.first);
        }

        cout << ans << endl;
    }
}