#include <iostream>
#include <vector>

using namespace std;
vector<int> values;


void solve() {
    int n; cin >> n;
    //for(int i = 0; i <= 100; i++) cout << values[i] << endl;

    cout << values[n] << endl;
}


int main() {
    int t; cin >> t;
    int k = 0, counter = 0, sum = 0;
    for(int i = 0; i <= 200000; i += 10) {
        if(i % 10 == 0) {
            int temp = i;
            k = 0;
            while(temp > 0) {
                int d = temp % 10;
                temp = temp / 10;
                k += d;
            }
            //cout << k << endl;
        }
        for(int j = k; j < (k+10); j++) {
            sum += j;
            values.push_back(sum);
        }
        k++;
    }
    while(t-- > 0) solve();
    return 0;
}