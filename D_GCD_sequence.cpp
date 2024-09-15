#include <bits/stdc++.h>
#include <numeric>

using namespace std;

#define ll long long

int gcd(int a, int b)
{
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    if (a == 0) {
        return b;
    }
    return a;
}

bool solve(vector<int> arr, int index) {
    arr.erase(arr.begin() + index);
    for(int i = 0; i < arr.size()-1; i++) {
        int hcf2 = gcd(arr[i], arr[i+1]);
        arr[i] = hcf2;
    }

    if(is_sorted(arr.begin(), arr.end())) return 1;

    return 0;
}


int main() {
    int tc =1; cin >> tc;
    for(int t =1; t <=tc; t++) {
        int n; cin >> n;
        vector<int> arr(n, 0);
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        vector<int> hcf;
        for(int i = 0; i < n-1; i++) {
            int hcf2 = gcd(arr[i], arr[i+1]);
            hcf.push_back(hcf2);
        }

        if(is_sorted(hcf.begin(), hcf.end())) {
            cout << "YES" << endl;
            continue;
        }
        else {
            int index = 0;
            
            for(int i = 0; i < n-1; i++) {
                if(hcf[i] > hcf[i+1]) {
                    index = i;
                    break;
                }
            }
            
            if(solve(arr, index) || solve(arr, index+1) || solve(arr, index+2)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}