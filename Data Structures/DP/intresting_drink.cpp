#include<bits/stdc++.h>
using namespace std;

int binary_search(int* arr,int low, int high, int e){
    /* Finds Element e in given array a.
        Returns index if found
        Returns -1 otherwise*/

    int mid = (high + low) / 2;
    if(high-low+1>=1){    
    if (arr[mid]==e) return mid;
    else if (e < arr[mid]){
        return binary_search(arr, low, mid-1, e);
    }
    else
        return binary_search(arr, mid+1, high, e);}
    return mid;
}
void drink(int* b, int* a, int m, int n){
    
    for (int i = 0; i < m; i++)
    {
        if(b[i]>=a[0] && b[i]<a[n-1]){
            int x = binary_search(a, 0,n, b[i])+1;
            while (a[x]==b[i] && x<n)
                x++;
            cout << x << "\n";
        }
        else if(b[i]>=a[n-1])
            cout << n << "\n";
        else
            cout << 0 << "\n";
    }
}
int main(int argc, char const *argv[])
{
    int n; cin >> n; int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int m; cin >> m; int brr[m];
    for (int i = 0; i < m; i++)
        cin >> brr[i];
    // int n =10; int arr[n] = {3,3,3,3,3,3,3,3,3,3};
    sort(arr, arr + n);
    // cout << '\n';
    drink(brr, arr, m, n);
    // sort(arr, arr + n);
    // if
    
    // cout << binary_search(arr, 0, n, 4)+1;
    return 0;
}
