#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tc; cin >> tc;
    for(int t = 1; t <= tc; t++) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> a(n), b(m);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];

        map<int, int> mp, isVisited;
        for(int i = 0; i < m; i++) mp[b[i]]++;

        queue<int> q;
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            q.push(a[i]);
            if(mp[a[i]]) {
                if(isVisited[a[i]] < mp[a[i]]) cnt++;
                isVisited[a[i]]++;
            }
        }
        int ans = 0;
        if(cnt >= k) ans = 1;


        for(int i = m; i < n; i++) {
            int top = q.front();
            if(isVisited[top] > 0) {
                isVisited[top]--;
                if(isVisited[top] < mp[top]) cnt--;
            }
            q.pop();
            q.push(a[i]);
            if(mp[a[i]]) {
                if(isVisited[a[i]] < mp[a[i]]) cnt++;
                isVisited[a[i]]++;
            }
            if(cnt >= k) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}