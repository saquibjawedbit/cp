
#include <bits/stdc++.h>

using namespace std;


    int solve(int left, int right) {
        if(left == right) return 0;
        int mid = (right - left)/3 * 2 + left;
        int ans = max(solve(left, mid-1), solve(mid+1, right)) + mid;
        return ans;
    }


    int getMoneyAmount(int n) {
        int ans = solve(1, n);
        return ans;
    }

int main() {
    int ans = getMoneyAmount(10);
    cout << ans << endl;
    return 0;
}
