#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int *arr1 = new int[n];
    int *arr2 = new int[n];
    for(int i =0; i < n; i++) cin >> arr1[i];
    for(int i =0; i < n; i++) cin >> arr2[i];

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + n);

    int i = 0, j = 0;
    int count  =0;
    while( i < n && j < n) {
        if(arr1[i] > arr2[j]) j++;
        else if(arr1[i] < arr2[j]) i++;
        else {
            count++;
            int temp = j+1;
            while(temp < n && arr1[i] == arr2[temp]) {
                count++;
                temp++;
            }
            temp = i+1;
            while(temp < n && arr1[temp] == arr2[j]) {
                count++;
                temp++;
            }
            j++;
            i++;
        }

    }

    cout << count << endl;
}

int main() {
    solve();
    return 0;
}