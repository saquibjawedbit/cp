#include <iostream>
#include <map>

using namespace std;

int main() {
    long long t; cin >> t;
    while(t-- > 0) {
        long long n, x, y; cin >> n >> x >> y;
        long long *arr = new long long[n];

        for(long long i = 0; i < n; i++) cin >> arr[i];

        long long ans = 0;
        map<pair<long long, long long>, long long> mp;
        for(long long i = 0; i < n; i++) {
            ans += mp[make_pair((x-arr[i] % x) %x, arr[i] % y)];
            mp[make_pair(arr[i] % x, arr[i] % y)]++;
        }
        cout << ans << endl;
    }
    return 0;
}