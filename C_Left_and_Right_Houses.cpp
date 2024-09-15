#include <iostream>

using namespace std;

float calculatePathValue(float n, int i) {
    return abs(n/2 - i);
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0, nLeft = 0, nRight = 0;
    float pathValue = INT_MAX;

    for(auto v: s) {
        if(v == '0') nLeft++;
        else nRight++;
    }

    float rProbab = (float)nRight/n;
    float lProbab = 0;

    if(rProbab > 0.5f) {
        pathValue = calculatePathValue(n, 0);
    }

    int cLeft = 0;
    for(int i = 0; i < n-1; i++) {
        if(s[i] == '0') cLeft++;

        lProbab = (float)cLeft/(i+1);
        rProbab = (float)(nRight - (i+1 - cLeft))/(n-(i+1));
        //cout << "i: " << i << " " << lProbab << " " << rProbab << endl;
        if(lProbab >= 0.5f && rProbab >= 0.5) {
            float nPathValue = calculatePathValue(n, i+1);
            if(nPathValue < pathValue) {
                ans = i+1;
                pathValue = nPathValue;
            }
        }
    }

    lProbab = (float)nLeft/n;
    if(lProbab > 0.5 && calculatePathValue(n, n) < pathValue) ans = n;

    cout << ans << endl;

}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();
}