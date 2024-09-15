#include <iostream>

using namespace std;

void solve() {
   string s; cin >> s;
   char diff = s[0];
   bool isDiff = false;
   for(int i = 0; i < s.length(); i++) {
    if(diff != s[i]) {
        isDiff = true;
        swap(s[0], s[i]);
    }
   }

   if(isDiff) {
        cout << "YES" << endl;
        cout << s << endl;
   }
   else {
    cout << "NO" << endl;
   }
}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();
}