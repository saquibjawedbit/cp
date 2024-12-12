#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> arr(n);

        for (auto &v : arr)
            cin >> v.first;
        for (auto &v : arr)
            cin >> v.second;

        sort(arr.begin(), arr.end(), [](pair<ll, ll> &f, pair<ll, ll> &e)
             { return f.second > e.second; });

        map<ll, vector<ll>> mp;

        for (auto v : arr)
        {
            if (mp[v.first].empty())
            {
                mp[v.first].push_back(v.second);
            }
            else
            {
                mp[v.first].push_back(v.second + mp[v.first][mp[v.first].size() - 1]);
            }
        }

        vector<ll> ans(n, 0);
        for (auto v : mp)
        {
            for (ll i = 1; i <= min(n,(ll)v.second.size()); i++)
            {
                ll index = v.second.size() - (v.second.size() % i) - 1;
                ll score = 0;
                if (index >= 0 && index < v.second.size())
                    score = v.second[index];
                ans[i-1] += score;
            }
        }

        for(auto v: ans) cout << v << " ";


        cout << endl;
    }
}