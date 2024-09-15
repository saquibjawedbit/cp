#include <iostream>
#include <deque>

using namespace std;

int main() {
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    int n = 7;

    deque<int> mini;
    deque<int> maxi;

    for(int i = 0; i < k; i++) {
        while(!mini.empty() && arr[mini.front()] > arr[i]) mini.pop_back();
        while(!maxi.empty() && arr[maxi.front()] < arr[i]) maxi.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = arr[maxi.front()] + arr[mini.front()];

    for(int i = k; i < n; i++) {
        while(!maxi.empty() && i-maxi.front() >= k) maxi.pop_front();
        while(!mini.empty() && i-mini.front() >= k) mini.pop_front();


        while(!mini.empty() && arr[mini.front()] > arr[i]) mini.pop_back();
        while(!maxi.empty() && arr[maxi.front()] < arr[i]) maxi.pop_back();

        maxi.push_back(i);
        mini.push_back(i);


        //cout << maxi.front() << " " << mini.front() << endl;
        ans += arr[maxi.front()] + arr[mini.front()];
    }

    cout << ans << endl;
    
    return 0;
}