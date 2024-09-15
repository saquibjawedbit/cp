#include <iostream>

using namespace std;

class queue {
    int freeSpot  = 0;
    int *arr;
    int *next;
    int *front;
    int *back;
    int size = 0;

    public:
    queue(int n, int k) {
        next = new int[n];
        arr = new int[n];
        front = new int[k];
        back = new int[k];
        size = n;

        for(int i = 0; i < n; i++) {
            next[i] = i+1;
        }
        next[n-1] = -1;
        for(int i = 0; i < k; i++) {
            front[i] = -1;
            back[i] = -1;
        }
    }

    void enqeue(int element, int k) {
        
        if(freeSpot == -1) {
            cout << "No Empty space is present" << endl;
            return;
        }

        int index = freeSpot;

        freeSpot = next[index];

        if(front[k-1] == -1) {
            front[k-1] = index; 
        }
        else {
            next[back[k-1]] = index;   
        }

        next[index] = -1;

        back[k-1] = index;

        arr[index] = element;
    }

    int dequeue(int k) {
        if(front[k-1] == -1) return -1;
        
        int index = front[k-1];

        //Update Front
        front[k-1] = next[index];

        //Update next:
        next[index] = freeSpot;

        freeSpot = index;

        return arr[index];
    }

    void printArr() {
        for(int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    queue q(10, 3);
    q.enqeue(10, 1);
    q.enqeue(15, 1);
    q.enqeue(20, 2);
    q.enqeue(25, 1);
    

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    cout << q.dequeue(1) << endl;
    return 0;
}