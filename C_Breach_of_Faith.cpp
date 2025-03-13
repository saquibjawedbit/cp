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
        vector<ll> b(2 * n);

        for (auto &v : b)
            cin >> v;

        sort(b.begin(), b.end());
        ll left = 1, right = 2 * n - 2;

        vector<ll> ans;

        ans.push_back(b.back());
        ll sum = 0;
        for (int i = 1; i < (n) && right >= left; i++)
        {
            sum += b[left];
            ans.push_back(b[left++]);
            sum -= b[right];
            ans.push_back(b[right--]);
        }


        ll req = b.front() - sum + b.back();

        ans.push_back(abs(req));
        ans.push_back(b.front());

        for (auto v : ans)
            cout << v << " ";
        cout << endl;
    }
}