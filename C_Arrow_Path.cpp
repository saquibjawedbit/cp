#include <iostream>

using namespace std;

bool path(char **a, int **isVisited, int n, int x = 0, int y = 0) {
    if(x == 1 && y == n-1) return true;

    isVisited[x][y] = 1;

    //cout << "Current Index: " << x << " " << y << endl;

    bool result = false;
    //Left
    if(!result && y != 0) {
        if(x == 1 && y-1 == n-1) result = true;
        isVisited[x][y-1] = 1;
        if(!result) {
            if(y-1 >= 0 && a[x][y-1] == '>' && isVisited[x][y] != 1) result = path(a,isVisited, n, x, y);
            else if(y-2 >= 0 && isVisited[x][y-2] != 1) result = path(a,isVisited, n, x,y-2);
        }
        isVisited[x][y-1] = 0;
    }
    //Right
    if(!result && y != n-1) {
        if(x == 1 && y+1 == n-1) result = true;
        isVisited[x][y+1] = 1;
        if(!result) {
            if(y+2 < n && a[x][y+1] == '>' && isVisited[x][y+2] != 1) result = path(a,isVisited, n, x, y+2);
            else if(isVisited[x][y] != 1) result = path(a,isVisited, n, x,y);
        }
        isVisited[x][y+1] = 0;
    }
    //Up
    if(!result && x == 1) {
        //Step 1:
        if(x-1 == 1 && y == n-1) result = true;
        isVisited[x-1][y] = 1;
        if(!result) {
            if(a[x-1][y] == '>' && isVisited[x-1][y+1] != 1) result = path(a,isVisited, n, x-1, y+1);
            else if(y-1 >= 0 && isVisited[x-1][y-1] != 1) result = path(a,isVisited, n, x-1,y-1);
        }
        isVisited[x-1][y] = 0;
    }
    //Down
    if(!result && x == 0) {
        if(x+1 == 1 && y == n-1) result = true;
        isVisited[x+1][y] = 1;
        if(!result) {
            if(a[x+1][y] == '>' && isVisited[x+1][y+1] != 1) result = path(a,isVisited, n, x+1, y+1);
            else if(y-1 >= 0 &&isVisited[x+1][y-1] != 1) result = path(a,isVisited, n, x+1,y-1);
        }
        isVisited[x+1][y] = 0;
    }


    return result;
    
}

void solve() {
    int n; cin >> n;
    char *a[2];
    int *isVisited[2];

    for(int i = 0; i < 2; i++) {
        a[i] = new char[n];
        isVisited[i] = new int[n];
    }

    for(int i = 0; i < 2; i++) {
        for(int j= 0; j < n; j++) cin >> a[i][j];
    }

    bool result = path(a, isVisited, n);

    if(result) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int main() {
    int t; cin >> t;
    while(t-- > 0) solve();
}