#include<bits/stdc++.h>
using namespace std;
int maxSubarray(int* arr,int n){
    int best = arr[0];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = max(arr[i],sum+arr[i]);
        best = max(best,sum);
    }
    return best;
}
int flipping(int* arr, int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (arr[i] == 0)
            arr[i] = 1;
        else if(arr[i] == 1)
            arr[i] = -1;
    }
    return sum + maxSubarray(arr, n);
}

int main(int argc, char const *argv[])
{
    int a[4] = {1, 0, 0, 1};
    cout << flipping(a, 4);
    return 0;
}
