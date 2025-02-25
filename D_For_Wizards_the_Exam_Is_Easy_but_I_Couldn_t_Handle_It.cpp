#include <bits/stdc++.h>

using namespace std;

#define ll long long

class OrderedSet {
public:
    multiset<int> s;

    // Insert an element into the set
    void insert(int x) {
        s.insert(x);
    }

    // Count how many elements are greater than x in O(log n)
    int countGreater(int x) {
        return distance(s.upper_bound(x), s.end());
    }

    // Count how many elements are less than x in O(log n)
    int countLess(int x) {
        return distance(s.begin(), s.lower_bound(x));
    }
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc; cin >> tc;
    for(ll t = 1; t <= tc; t++) {
        // Code here
        ll n; cin >> n;
        vector<ll> arr(n);

        for(auto &v: arr) cin >> v;
        vector<ll> suffMax(n), suffMin(n);
        OrderedSet s;
        for(int i = n-1; i >= 0; i--) {
            suffMin[i] = s.countLess(arr[i]);
            s.insert(arr[i]);
        }
        
        ll maxiVal = 0, maxiIndex = 0;
        ll maxPrev = 0, maxL = 0, maxR = 0;
        for(int i = 0; i < n; i++) {
            maxiVal = suffMin[i];
            maxiIndex = i;
            ll r = maxiIndex+1, g = 0, l = 0, prev = 0;
            for(int i = maxiIndex; i < n; i++) {
                if(arr[maxiIndex] < arr[i]) {
                    g++;
                } else if(arr[maxiIndex] > arr[i]) {
                    l++;
                }
                
    
                if(l > g && (l-g) > prev) {
                    r = i+1;
                    prev = l-g;
                }
            }
    
            if(prev >= maxPrev) {
                maxPrev = prev;
                maxL = maxiIndex+1;
                maxR = r;
            }
        }

        cout << maxL << " " << maxR << endl;
       
        
    }
}