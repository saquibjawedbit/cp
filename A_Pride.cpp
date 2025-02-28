#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool all(vector<ll> &arr)
{
    bool ans = 1;
    for (auto v : arr)
        if (v != 1)
            return false;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1; // cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        // Code here

        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];

        // Case 1: Check if there's already a 1 in the array.
        int ones = 0;
        for (ll v : a)
        {
            if (v == 1)
                ones++;
        }
        if (ones > 0)
        {
            // Spread the 1's to all other elements.
            cout << n - ones << "\n";
            return 0;
        }

        ll overallGCD = a[0];
        for (int i = 1; i < n; i++)
        {
            overallGCD = std::gcd(overallGCD, a[i]);
        }
        if (overallGCD != 1)
        {
            cout << -1 << "\n";
            return 0;
        }

        int best = n + 1;
        for (int i = 0; i < n; i++)
        {
            ll g = a[i];
            for (int j = i; j < n; j++)
            {
                g = std::gcd(g, a[j]);
                if (g == 1)
                {
                    best = min(best, j - i + 1);
                    break;
                }
            }
        }

        cout << (best - 1) + (n - 1) << "\n";
    }
}