#include<bits/stdc++.h>
using namespace std;

int maxSubarray(int* arr,int n){
    int best = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = max(arr[i],sum+arr[i]);
        best = max(best,sum);
    }
    return best;
}

int main(int argc, char const *argv[])
{
    int a[8] = {-1, 2, 4, -3, 5, 2, -5, 2};
    cout << maxSubarray(a,8);
    return 0;
}
