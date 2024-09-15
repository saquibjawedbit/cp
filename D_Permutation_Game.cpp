#include <iostream>
#include <vector>

using namespace std;

long long getMaxScore(long long *a, long long *p, long long n, int startIndex, int k) {

    long long maxScore = 0, currentIndex = startIndex-1;
    long long currentScore = 0;
    vector<int> vs(n, 0);
    for(int i = 0; i < k; i++) {
        currentScore += a[currentIndex];
        long long cScore = currentScore + (long long)(k-i-1) * a[currentIndex];
        maxScore = max(maxScore, cScore);
        if(vs[currentIndex] == 1) break;
        else vs[currentIndex] = 1;
        currentIndex = p[currentIndex] -1;
    }
    return maxScore;
}

void solve() {
    int n, k, b, s; cin >> n >> k >> b >> s;
    long long *p = new long long[n];
    long long *a = new long long[n];

    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> a[i];
      

    long long bodyaScore = getMaxScore(a, p, n, b, k);
    long long sashaScore = getMaxScore(a, p, n, s, k);


    if(bodyaScore > sashaScore) cout << "Bodya" << endl;
    else if(sashaScore > bodyaScore) cout << "Sasha" << endl;
    else cout << "Draw" << endl;
}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();

    return 0;
}