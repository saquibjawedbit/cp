#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            maxi = max(maxi, arr[i]);
        }
        for(int i =n-1; i >= 0; i--) {
            int left = 0, right = i;
            while(right >= left) {
                arr[left] = arr[left] & arr[right];
                arr[right] = arr[left];
                left++; right--;
            }
        }
        int mini = INT_MAX;
        for(int i = 0; i < n; i++) {
            mini = min(mini, arr[i]&maxi);
        }
        cout << mini << endl;
    }
    return 0;
}