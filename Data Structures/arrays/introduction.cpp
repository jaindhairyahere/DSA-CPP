#include<iostream>
using namespace std;

void printArray(int* array, int n){
    for (int i = 0; i < n; i++)
    {
        cout << array[i]<<" ";
    }
    cout << "\n";
    return;
}
int main(int argc, char const *argv[])
{
//Array Declaration
int a1[5];
int a2[5] = {1, 2, 3,4,5};
int a3[5]={};
int a4[5] = {1};
int a5[5] = {1, 2, 3};
int a6[8] = {1, 2, 3, 4, 5, 6, 7, 8};
// int a6[5] = {[0, 1, 4] = 10};
// int a7[] = {[0, 4] = 9};

printArray(a1, 5);
printArray(a2, 5);
printArray(a3, 5);
printArray(a4, 5);
printArray(a5, 5);
printArray(a6, 8);
//  << a6 << "\n"
//  << a7;
return 0;
}
