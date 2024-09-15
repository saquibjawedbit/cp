#include <iostream>

using namespace std;

void solve() {
    long long n, k; cin >> n >> k;
    int *arr = new int[n];

    for(int i = 0; i < n; i++) cin >> arr[i];
    
    int s = 0, e = n-1, ans = 0;

    while(k > 0 && s <= e && ans < n) {
        long long nAttacks = min(arr[s], arr[e]);
        if((k - 2 * nAttacks) < 0) {
            int attacks = k&1 ? (k-1)/2 : k/2;
            arr[s] -= attacks; arr[e] -= attacks;
            k -= 2 * attacks;
            if(arr[s] <= 0) {
                ans++; s++;
            }
            else if(arr[e] <= 0) {
                ans++; e--;
            }
            bool isFirst = true;
            while(k > 0 && s <= e) {
                if(isFirst) {
                    if(--arr[s] <= 0) {
                        s++; ans++;
                    }
                }
                else {
                    if(--arr[e] <= 0) {
                        e--; ans++;
                    }
                }
                isFirst = !isFirst;
                k--;
            }

            break;
        }
        else {
            k -= 2 * nAttacks;
            arr[s] -= nAttacks;
            arr[e] -= nAttacks;
            if(arr[s] == arr[e] && s != e) {
                ans += 2;
                s++; e--;
            }
            else {
                ans++;
                if(arr[s] > arr[e]) e--;
                else s++;
            }
        }
    }

    cout << ans << endl;

}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();

    return 0;
}