#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    long long, 
    null_type, 
    less_equal<long long>, 
    rb_tree_tag, 
    tree_order_statistics_node_update> ordered_set;

#define ll long long int

const ll MOD = 1e9+7;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 1ll, 0ll);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    ordered_set freq;
    ll ans = 0;

    for (ll i = n; i >= 1ll; --i)
    {
        ans = (ans + freq.order_of_key(a[i]));
        
        freq.insert(2 * a[i]);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc;
    cin >> tc;
    for (ll t = 1; t <= tc; t++) solve();
}
