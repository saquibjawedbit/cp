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
    for (ll t = 1; t <= tc; t++)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        for (auto &v : arr)
            cin >> v;

        sort(arr.begin(), arr.end());

        map<ll, vector<ll>> mp;
        for (auto v : arr)
        {
            mp[v % k].push_back(v);
        }
        ll ans = 0, nOdd = 0;
        for (auto v : mp)
        {
            vector<ll> suffix, prefix;
            ll sum = 0, nIndex = 0;
            suffix.push_back(0); prefix.push_back(0);
            while((nIndex + 1) < v.second.size())
            {
                sum += v.second[nIndex+1] - v.second[nIndex];
                prefix.push_back(sum);
                nIndex += 2;
            }
            if ((v.second.size() & 1) == 0)
            {
                ans += (prefix[prefix.size() - 1] - prefix[0]) / k;
            }
            else
            {
                ll nAns = INT_MAX;
                nOdd++;
                if ((nOdd > 0 && (n % 2) == 0) || (nOdd > 1 && (n % 2 != 0)))
                {
                    ans = -1;
                    break;
                }
                sum = 0;
                nIndex = v.second.size()-1;
                while((nIndex - 1) >= 0)
                {
                    sum += v.second[nIndex] - v.second[nIndex - 1];
                    suffix.push_back(sum);
                    nIndex -= 2;
                }
                ll left = 0, right = suffix.size() - 1;
                while (right >= 0 && left < prefix.size())
                {
                    ll tempSum = (prefix[left] + suffix[right]) / k;
                    nAns = min(nAns, tempSum);
                    right--;
                    left++;
                }
                ans += nAns;
            }
        }
        cout << ans << endl;
    }
}