#include <iostream>

using namespace std;

class heap
{

    int arr[100];
    int size;

public:
    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {

        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            if (arr[size / 2] < arr[index])
            {
                swap(arr[size / 2], arr[index]);
                index = size / 2;
            }
            else
                return;
        }
    }

    void pop()
    {
        if (size <= 0)
            return;

        arr[1] = arr[size--];
        int index = 1;
        while (index < size)
        {
            int left = 2 * index, right = 2 * index + 1;

            if (left <= size && right <= size)
            {
                if (arr[left] > arr[index] && arr[left] > arr[right])
                {
                    swap(arr[left], arr[index]);
                    index = left;
                }
                else if (arr[right] > arr[index] && arr[right] > arr[left])
                {
                    swap(arr[right], arr[index]);
                    index = right;
                }
                else
                    return;
            }
            else if (left <= size && arr[left] > arr[index])
            {
                swap(arr[left], arr[index]);
                index = left;
            }
            else if (right <= size && arr[right] > arr[index])
            {
                swap(arr[right], arr[index]);
                index = right;
            }
            else
                return;
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

void heapify(int *arr, int size, int index)
{

    int i = index;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= size && right <= size)
    {
        if (arr[left] > arr[index] && arr[left] >= arr[right])
        {
            swap(arr[left], arr[index]);
            index = left;
        }
        else if (arr[right] > arr[index] && arr[right] >= arr[left])
        {
            swap(arr[right], arr[index]);
            index = right;
        }
    }
    else if (left <= size && arr[left] > arr[index])
    {
        swap(arr[left], arr[index]);
        index = left;
    }
    else if (right <= size && arr[right] > arr[index])
    {
        swap(arr[right], arr[index]);
        index = right;
    }

    if (index != i)
        heapify(arr, size, index);
}

void sort(int *arr, int size) {
    if(size <= 0) return;


    while(size > 1) {
        swap(arr[1], arr[size--]);
        heapify(arr, size, 1);
    }
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    // h.pop();
    // h.print();

    int arr[] = {-1, 4, 3, 2, 1};
    int n = 4;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = 1; i < 6; i++)
        cout << arr[i] << " ";
    cout << endl;


    sort(arr, n);
    for (int i = 1; i < n+1; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}