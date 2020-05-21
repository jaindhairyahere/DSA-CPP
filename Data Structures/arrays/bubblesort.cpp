#include<iostream>
using namespace std;

void swap(int& a,int& b){
    int temp=a;
    a = b;
    b = temp;
}

void bubbleSort(int* a, int n){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-1; j++)
            {
                if (a[j]>a[j+1])
                    swap(a[j], a[j + 1]);
            }
    }
}

// ostream& operator<<(ostream& stream, int* a){
//     int n = sizeof(a);
//     for (int i = 0; i < n; i++)
//     {
//         stream << a[i] <<" ";
//     }
//     return stream;
// }

int main(int argc, char const *argv[])
{
    int arr[5] = {5, 2, 3, 4, 1};
    bubbleSort(arr, 5);
    cout << arr;
    return 0;
}
