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
        int n;
        cin >> n;
        vector<ll> arr(n);
        for (auto &v : arr)
            cin >> v;

        ll remainder = 1;

        for (int i = 0; i <= 63; i++)   {
            int ones = 0, zeroes = 0;
            for (int j = 0; j < arr.size(); j++)    {
                if ((arr[j] & (1LL << i)) != 0) ones++;
                else zeroes++;
            }
            if (ones == arr.size() || zeroes == arr.size()) {
                remainder += (1LL << i);
            }
            else    {
                remainder += (1LL << i);
                break;
            }
        }

        cout << remainder  << endl;
    }
}