#include <bits/stdc++.h>

using namespace std;

#define ll long long

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0ll);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    pbds ms;

    int ans = 0;
    for (int i = n; i >= 1; --i)
    {
        ans += ms.order_of_key((a[i]));
        ms.insert(2 * a[i]);
    }
    cout << ans << endl;
}

int main() {
    ll tc = 1;
    for(ll t  =1; t <= tc; t++) {
        
    }
}