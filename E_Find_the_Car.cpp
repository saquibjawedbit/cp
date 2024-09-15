#include <iostream>

using namespace std;

void solve() {
    int n, k, q; cin >> n >> k >> q;
    int *distance = new int[k+1];
    int *time = new int[k+1];
    long long *distanceq = new long long[q];

    for(int i = 1; i < k+1; i++) cin >> distance[i];
    for(int i = 1; i < k+1; i++) cin >> time[i];
    for(int i = 0; i < q; i++) cin >> distanceq[i];


    distance[0] = time[0] = 0;

    for(int i = 0; i < q; i++) {
        int s = 0, e = k;
        long long ans = 0;
        int index = 0;
        while(s <= e) {
            int mid = e + (s - e)/2;
            if(distance[mid] == distanceq[i]) {
                index = mid;
                break;
            }
            else if(distance[mid] > distanceq[i]) {
                e = mid - 1; 
            }
            else {
                s = mid + 1;
                index = mid;
            }
        }
        if(distance[index] == distanceq[i]) {
            cout << time[index] << " ";
            continue;
        }
        ans = time[index] + ((distanceq[i] - distance[index]) * (time[index+1] - time[index])) / (distance[index+1] - distance[index]);
        cout << ans << " ";
    }
    cout << endl;

}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();
    return 0;
}