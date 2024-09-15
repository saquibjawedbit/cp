#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc =1;
    cin >> tc;
    for(ll t  =1; t <= tc; t++) {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &v: arr) cin >> v;
        string s; cin >> s;
        vector<ll> ans(n, -1);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            if(ans[i] != -1) continue;

            int cntBlack = s[i] == '0' ? 1 : 0, index = i;
            st.push(i);

            while((arr[index]-1) != i) {
                index = arr[index]-1;
                if(s[index] == '0') cntBlack++;
                st.push(index);
            }

            while(!st.empty()) {
                int index = st.top();
                ans[index] = cntBlack;
                st.pop();
            }
        }


        for(auto &v: ans) cout << v << " ";
        cout << endl;
    }
} 