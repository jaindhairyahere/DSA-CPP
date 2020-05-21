#include<iostream>
using namespace std;

int max_sum(int* a){
    int s=0;
    int curVal = 0;
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++)
    {   
        s += a[i];
        curVal += i * a[i];
    }
    int maxVal = curVal;
    for (int i = 0; i < n; i++)
    {
        curVal = curVal + s - a[n - 1]*(n+1);
        if (curVal>maxVal)
            maxVal = curVal;
    }
    return maxVal;
}

int main(int argc, char const *argv[])
{
    int arr[10];
    return 0;
}