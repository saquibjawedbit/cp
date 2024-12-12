#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(ll n, ll m) {
    queue<pair<ll, ll>> q;
    unordered_set<ll> mp;

    q.push({n, 0});
    mp.insert(n);

    while (!q.empty()) {
        auto &[cur, steps] = q.front();
        q.pop();

        if (cur == m) return steps;

        if (cur % 2 == 0 && cur / 2 >= m &&  mp.find(cur / 2) == mp.end()) {
            q.push({cur / 2, steps + 1ll});
            mp.insert(cur / 2);
        }
        if (cur % 3 == 0 && cur / 3 >= m && mp.find(cur / 3) == mp.end()) {
            q.push({cur / 3, steps + 1ll});
            mp.insert(cur / 3);
        }
        if (cur - 1 >= m && mp.find(cur - 1) == mp.end()) {
            q.push({cur - 1, steps + 1ll});
            mp.insert(cur - 1);
        }
    }

    return -1; 
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        ll n, m;
        cin >> n >> m;
        cout << solve(n, m) << endl;
    }
    return 0;
}
