#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a)
        cin >> i;

    ll sum = accumulate(a.begin(), a.end(), (ll)0);  // Calculate total number of monsters
    sort(a.rbegin(), a.rend());  // Sort hordes in descending order
    
    ll ans = 0;
    ans += (sum + 1) / 2;  // Initial number of attacks (at least half the sum)
    sum >>= 1;  // Simulate half of the monsters are destroyed by ultimate attacks
    
    for (auto &i : a) {
        if (sum >= i) {
            sum -= i;  // Use ultimate attack on the horde
            ans++;
        } else if (sum) {
            ans++;  // One more attack if the sum is insufficient
            break;
        } else {
            break;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
