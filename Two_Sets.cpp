#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n; cin >> n;
    long long int sum = (n * (n+1))/2;

    if(sum & 1) {
        cout << "NO" << endl;
        return 0;
    }

    sum = sum/2;
    vector<long long> set1, set2;
    set1.push_back(n);
    long long sum1 = n, sum2 = 0;
    for(long long i = n-1; i > 0; i--) {
        if((sum - (sum1 + i) >= 0)) {
            set1.push_back(i);
            sum1 += i;
        }
        else {
            set2.push_back(i);
            sum2 += i;
        }
    }


    if(sum1 == sum2) {
        cout << "YES" << endl;
        cout << set1.size() << endl;
        for(auto v: set1) cout << v << " ";
        cout << endl;
        cout << set2.size() << endl;
        for(auto v: set2) cout << v << " ";
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }

}