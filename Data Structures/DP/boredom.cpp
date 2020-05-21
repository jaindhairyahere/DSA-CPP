#include<bits/stdc++.h>
using namespace std;
#define MAX 1e5



long int boredom(int* a,int n){
    long long int arr[int(MAX) + 1] = {0};
    for (int i = 0; i < n; i++) arr[a[i]]+= a[i];
    for (int i = 2; i <= MAX;i++){
        arr[i] = max(arr[i] + arr[i - 2], arr[i - 1]);
        if(i>99990)
            cout << arr[i] << " ";
    }
    cout << "\n";
    return arr[int(MAX)];
}

int main(int argc, char const *argv[])
{
    freopen("../arrays/array.txt", "r", stdin);
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    cout << boredom(array, n);
    return 0;
}
