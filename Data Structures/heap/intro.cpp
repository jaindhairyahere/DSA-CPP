#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int left(int i){
    // Left Child of parent @ i
    // int n = sizeof(arr)/sizeof(arr[0]);
    return 2 * i + 1;
}

int right(int i){
    // Left Child of parent @ i
    return 2 * i + 2;
}

int height(int* arr, int n){
    return log2(n)/1;
}

void printHeap(int* arr, int n){
    int i = 0;
    for (int i = (n - 1) / 2; i > 0; i--)
    {

        for (int j = 0; j < 2^i; j++)
        {
            cout << arr[2^i + j];
        }
        cout << "\n";
    }
}

void printArray(int* arr, int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void max_heapify(int* arr, int i, int n){
    // correct a single violation of the heap property in a subtree at its root
    int largest = i;
        if (left(i)<n && arr[left(i)]>arr[i]){
            largest = left(i);
        }
        if (right(i)<n && arr[right(i)]>arr[largest]){
            largest = right(i);
        }
        swap(arr + i, arr + largest);
        if (largest != i)
            max_heapify(arr, largest, n);
}


void build_heap(int* arr, int n){
    //produce a max-heap from an unordered array
    // Assuming that Left Subtrees and Right Subtrees of parent @ i are MAXHEAPS
    for (int i = n  / 2; i > 0; i--)
        max_heapify(arr, i, n);
    // printArray(arr, n);
}

void HeapSort(int* arr, int n){
    int i = n;
    build_heap(arr, n);
    while (i >= 1)
    {
        swap(arr, arr + i - 1);
        max_heapify(arr, 0, i-1);
        i--;
    }
    printArray(arr, n);
}

int main(int argc, char const *argv[])
{
    int a[10] = {16, 4, 10, 8, 7, 9, 3, 2, 14, 1};
    HeapSort(a, 10);
    return 0;
}