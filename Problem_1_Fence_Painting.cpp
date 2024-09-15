#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
    freopen("paint.in","r", stdin);
    freopen("paint.out", "w", stdout);
    long long a, b; cin >> a >> b;
    long long c, d; cin >> c >> d;

    long long ans = 0;
    if(b >= c && b <= d) ans = d - min(a, c);
    else if(a >= c && a <= d) ans = b - min(a, c);
    else if(a >= c && b >= c && a <= d && b <= d) ans = d - c;
    else if(c >= a && d >= a && c <= b && d <= b) ans = b - a;
    else ans = (d - c) + (b - a);
    cout << ans << "\n";

}