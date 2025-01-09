#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

int main()
{

    ios_base::sync_with_stdio(false); // Disable sync with C I/O
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1;
    // cin >> tc;
    for (ll t1 = 1; t1 <= tc; t1++)
    {
        string t, a;
        cin >> t >> a;
        map<char, ll> mp, mp1;

        for (auto v : t)
            mp[v]++;

        for (auto v : a)
            mp1[v]++;



        mp1['2'] += mp1['5'];
        mp1['6'] += mp1['9'];

        mp['2'] += mp['5'];
        mp['6'] += mp['9'];

        // cout << mp1['2'] <<" " << mp['2'] <<  endl;
        ll ans = INT_MAX;

        for (auto v : mp)
        {
            if(v.first == '5' || v.first == '9') continue;

            if(v.second == 0) continue;

            // cout << v.first <<" "<< mp1[v.first] << endl;

            ans = min(ans, mp1[v.first] / v.second);
        }

        cout << ans << endl;
    }
}