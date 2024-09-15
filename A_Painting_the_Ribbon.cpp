#include <iostream>

using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int *arr = new int[n];

    int m_c = 1,k_c = 0;
    for(int i = 0; i < n; i++) {
        
        arr[i] = m_c;
       // cout << arr[i] << " ";
        if(m_c++ != 1) k_c++;
        if(m_c > m) m_c = 1;
    }   
    if(k_c <= k) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();
    return 0;
}