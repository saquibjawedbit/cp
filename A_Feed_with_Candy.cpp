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
    for (ll t = 1; t <= tc; t++)
    {
        ll n, k;
        cin >> n >> k;
        vector<pair<ll, ll>> type1, type2;

        for (int i = 0; i < n; i++)
        {
            ll t, a, b;
            cin >> t >> a >> b;
            if (t == 1)
                type1.push_back({a, b});
            else
                type2.push_back({a, b});
        }

        sort(type1.begin(), type1.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
            if(a.first == b.first) return a.second > b.second;

            return a.first < b.first;
        });
        sort(type2.begin(), type2.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
            if(a.first == b.first) return a.second > b.second;

            return a.first < b.first;
        });


        ll ans = 0, ans2 = 0;
        ll index1 = 0, index2 = 0;
        ll temp = k;
        vector<pair<ll,ll>> nType1 = type1;
        vector<pair<ll,ll>> nType2 = type2;
        for (ll i = 0; i < n; i++)
        {
            if (i % 2 == 1)
            {
                ll bestIndex = -1;
                for(int j = 0; j < type1.size(); j++)
                {
                    if(type1[j].first <= k)
                    {
                        if(bestIndex == -1) bestIndex = j;
                        else if(type1[bestIndex].second < type1[j].second) bestIndex = j;
                    }
                }

                if(bestIndex == -1) break;
                ans++;
                k += type1[bestIndex].second;
                type1.erase(type1.begin() + bestIndex);
            }
            else
            {
                ll bestIndex = -1;
                for(int j = 0; j < type2.size(); j++)
                {
                    if(type2[j].first <= k)
                    {
                        if(bestIndex == -1) bestIndex = j;
                        else if(type2[bestIndex].second < type2[j].second) bestIndex = j;
                    }
                }

                if(bestIndex == -1) break;
                ans++;
                k += type2[bestIndex].second;
                type2.erase(type2.begin() + bestIndex);
            }
        }



        index1 = 0; index2 = 0; k = temp;
        for (ll i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                ll bestIndex = -1;
                for(int j = 0; j < nType1.size(); j++)
                {
                    if(nType1[j].first <= k)
                    {
                        if(bestIndex == -1) bestIndex = j;
                        else if(nType1[bestIndex].second < nType1[j].second) bestIndex = j;
                    }
                }

                if(bestIndex == -1) break;
                ans2++; k += nType1[bestIndex].second;
                nType1.erase(nType1.begin() + bestIndex);
            }
            else
            {
                ll bestIndex = -1;
                for(int j = 0; j < nType2.size(); j++)
                {
                    if(nType2[j].first <= k)
                    {
                        if(bestIndex == -1) bestIndex = j;
                        else if(nType2[bestIndex].second < nType2[j].second) bestIndex = j;
                    }
                }

                if(bestIndex == -1) break;
                ans2++; k += nType2[bestIndex].second;
                nType2.erase(nType2.begin() + bestIndex);
            }
        }


        cout << max(ans, ans2) << endl;
    }
}