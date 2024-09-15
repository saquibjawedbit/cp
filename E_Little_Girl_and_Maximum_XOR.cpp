#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b; cin >> a >> b;
    long long ans = 0;
    bool start = false;
    for(long long i = 63; i >= 0; i--) {
        long long a_bit = a & (1LL << i);
        long long b_bit = b & (1LL << i);

        //cout << i << " " << a_bit << " " << b_bit << endl;

        if(!start) {
            if(a_bit != 0 || b_bit != 0) {
                if((a_bit != 0 && b_bit == 0) || (a_bit == 0 && b_bit != 0)) {
                    ans ^= (1LL << i);
                    start = true;
                }
            }
        }
        else {
            ans ^= (1LL << i);
        }
    }

    cout << ans << endl;

    return 0;
}