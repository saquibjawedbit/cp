#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    string x, y;
    cin >> x >> y;
    string fa = "", fb = "";
    int n = x.size();
    for (int i = 0; i < n; ++i) {
      char minElement = min(x[i], y[i]);
      char maxElement = max(x[i], y[i]);

      if(fb > fa) {
          fa += maxElement;
          fb += minElement;
      }
      else {
        fa += minElement;
        fb += maxElement;
      }
    }


    cout << fa << '\n' << fb << '\n';
  }
}