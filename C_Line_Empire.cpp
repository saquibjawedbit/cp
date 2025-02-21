#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        // Code here
        ll n, a, b;
        cin >> n >> a >> b;
        vector<ll> arr(n + 1);
        arr[0] = 0;
        for (int i = 1; i < arr.size(); i++)
            cin >> arr[i];

        ll ans = 0;
        ll currentCapital = 0; 
        for (int i = 1; i <= n; i++)
        {
            ans += (arr[i] - currentCapital) * b;

            if (i < n && (n - i) * b > a)
            {
                ans += (arr[i] - currentCapital) * a;
                currentCapital = arr[i];
            }
        }

        cout << ans << endl;
    }
}