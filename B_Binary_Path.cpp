#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

void traverse(string *arr, int n, int x, int y,string &answers, int& count) {
    if(x == 1 && y == n-1) {
        answers += arr[x][y];
        return;
    }

    if(x >= 2 && y >= n) return;

    answers += arr[x][y];

    char nextRight = (y+1) < n ? arr[x][y+1] : 'z';
    char nextDown = (x + 1) < 2 ? arr[x+1][y] : 'z';

    //Right
    if(x == 1 && y == n-2) {
        traverse(arr, n, x, y+1, answers,count); 
        return;
    }
    if(x == 0 && y == n-1) {
        traverse(arr, n , x+1, y,  answers, count);
        return;
    }


    //Right
    if((y + 1) < n && nextRight <= nextDown) {
        if(nextRight == nextDown) count++;
        if(x != 1 && nextRight < nextDown) count = 1;
        traverse(arr, n, x, y+1, answers,count);
        
    }
    //Down 
    else if((x +1) < 2 && nextDown < nextRight) {
        traverse(arr, n , x+1, y,  answers, count);
    }
}   


int main() {
    int t; cin >> t;
    for(int k = 0; k < t; k++) {
        int n; cin >> n;
        string s[2];

        for(int i = 0; i < 2; i++) cin >> s[i];

        string answers = ""; 

        int count = 1;
        traverse(s,n,  0 , 0, answers, count);

        cout << answers << endl;
        cout << count << endl;
    }
}