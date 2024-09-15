#include <bits/stdc++.h>

#define ll long long

using namespace std;



int main() {
    int tc = 1;
    for(int t1 = 1; t1 <= tc; t1++) {
        int n, t; cin >> n >> t;
        map<int, int> mp;
        map<int, int> count;
        for(int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            mp[a] = b;
            count[a]++;
            count[b]++;
        }

        int cI; cin >> cI;
        vector<int> leafs;
        for(auto v: count)
        {
            if(v.second == 1) leafs.push_back(v.first);
        }

        int head = mp[leafs[0]] != 0 ? leafs[0] : leafs[1];

        int length = 0, currentIndex = 0;
        
        while(head != 0) {
            if(head == cI) currentIndex = length;
            length++;

            head = mp[head];
        }

        int leftDiff = currentIndex;
        int rightDiff = length - (currentIndex+1);

        //cout << leftDiff << " " << rightDiff << endl;

        if((leftDiff&1) || (rightDiff&1)) cout << "Ron" << endl;
        else cout << "Hermione" << endl;


    }
}