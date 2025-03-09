#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        // Code here
        ll n;
        cin >> n;
        vector<pair<ll, ll>> arr(n);
        
        for(auto &v: arr) {
            cin >> v.first >> v.second;
        }

        if(n == 1) cout << -1 << endl;

        map<pair<ll, ll>, queue<ll>> a;

        for(int i = 0; i < arr.size(); i++) {
            a[arr[i]].push(i);
        }

        sort(arr.begin(), arr.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
            if(a.first ==  b.first) return a.second > b.second;

            return a.first < b.first;
        });

        ll min = arr[0].first, right = arr[0].second;
        vector<ll> ans(n, 2);
        ans[a[arr[0]].front()] = 1;
        a[arr[0]].pop();
        bool pos = 0;
        for(int i = 1; i < arr.size(); i++) {
            // cout << arr[i].first << " " << right << endl;
            if(arr[i].first > right) {
                pos = 1;
                break;
            }
            else {
                ans[a[arr[i]].front()] = 1;
                a[arr[i]].pop();
                right = max(right, arr[i].second);
            }
        }

        if(!pos) {
            cout << -1 << endl;
        }
        else {
            for(auto v: ans) cout << v << " ";
            cout << endl;
        }


        
    }
}