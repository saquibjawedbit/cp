
/*
    --> Ankit singh sisodya
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

#define debug(...) 42
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
// #include "algo.h";
#endif

std::mt19937_64 rng{std::chrono::steady_clock::now().time_since_epoch().count()};

// smallest prime factor && spf[i] == i -> then the number is prime
// 100
const int N = 2e7 + 1;
int spf[N];
signed main()
{
    int cnt = 0;

    for (int i = 0; i < N; ++i)
        spf[i] = i;
    for (int i = 2; i < N; ++i)
    {
        if (spf[i] == i)
        {
            cnt++;
            for (int j = i * i; j < N; j += i)
            {

                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }

    cout << cnt;
}
