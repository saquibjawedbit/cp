#include <bits/stdc++.h>


using namespace std;

#define ll long long
#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);  // Disable sync with C I/O
    cin.tie(nullptr); 
    cout.tie(nullptr);
    ll tc = 1;
    // cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        ll x1, y1; cin >> x1 >> y1;
        ll x2, y2; cin >> x2 >> y2;

        ll n; cin >> n;
        string s; cin >> s;

        vector<ll> x(n+1, 0), y(n+1, 0);
        ll sumX = 0, sumY = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'U') {
                sumY++;
            }
            else if(s[i] == 'D') {
                sumY--;
            }
            else if(s[i] == 'L') {
                sumX--;
            }
            else if(s[i] == 'R') {
                sumX++;
            }
            x[i+1] = sumX;
            y[i+1] = sumY;
        }
        

        auto check = [&](ll mid) {
            ll currentX = x1 + sumX * (mid / n) + x[mid % n];
            ll currentY = y1 + sumY * (mid / n) + y[mid % n];


            ll dist = abs(currentX - x2) + abs(currentY - y2);

            if(dist <= (mid)) {
                return true;
            }

            return false;

        };

        // cout << check(2) << endl;


        ll left = 0, right = 1e18;
        ll ans = -1;
        while(right >= left) {
            ll mid = left + (right - left) / 2;
            if(check(mid)) {
                right = mid-1;
                ans = mid;
            }
            else {
                left = mid + 1;
            }
        }
        
        cout << ans << endl;
    }
}