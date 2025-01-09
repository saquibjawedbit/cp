#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> arr(n);
    for(auto &x : arr) cin >> x;

    auto maxContiguousSum = [&](const vector<long double> &v) {
        long double maxSoFar = 0, maxEndingHere = 0;
        for(long double x : v) {
            maxEndingHere = max(0.0L, maxEndingHere + x);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    };

    auto check = [&](long double x) {
        vector<long double> deviations(n);
        for(int i = 0; i < n; i++) {
            deviations[i] = arr[i] - x;
        }
        long double pos = maxContiguousSum(deviations);
        for(auto &d : deviations) d = -d;
        long double neg = maxContiguousSum(deviations);
        return max(pos, neg);
    };

    const long double eps = 1e-12;
    long double left = *min_element(arr.begin(), arr.end());
    long double right = *max_element(arr.begin(), arr.end());
    
    for(int i = 0; i < 150; i++) {
        long double mid = (left * 0.5L + right * 0.5L);
        long double val = check(mid);
        long double rval = check(mid + eps);
        
        if(val > rval) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << fixed << setprecision(6) << check((left + right) * 0.5L) << "\n";
    return 0;
}