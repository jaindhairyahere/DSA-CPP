#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

#define MAX 100000

int smallest_K(int* a, int k){
    int iter = 0;
    int min;
    for (int i = 0; i < MAX; i++)
    {
        iter += a[i];
        if(iter>=k){
            min = i;
            break;}
    }
    return min;
}

void swap(int& a, int& b){
    int temp = b;
    b = a;
    a = temp;
}

// void heapify(int* arr, ,int len){
//     if(len==0)
//         cout << "ERROR";
    
      

// }


// int heap(int* a,int n,int k){
//     int arr[k];
//     int i = 0;
//     heapify(arr);
//     for (i; i < n; i++)
//     {

//     }
    
// }

int main(int argc, char const *argv[])
{
    freopen("array.txt", "r", stdin);
    int size;
    cin >> size;
    int array[MAX] = {0};
    for (int i = 0; i < size; i++){
        int k;
        cin >> k;
        array[k]++;
    }

    int m;
    cin >> m;
    cout << endl;
    cout << smallest_K(array, m);
    return 0;
}
