#include<bits/stdc++.h>
using namespace std;

void swap(int& a,int& b){
    int temp=a;
    a = b;
    b = temp;
}

int* merge(int* a, int* b, int n1, int n2, int* newarr){
    // assuming both arrays are sorted
    // newarr = a;
    int a1[n1], a2[n2];
    for (int i = 0; i < n1; i++)
        a1[i] = a[i];
    for (int i = 0; i < n2; i++)
        a2[i] = b[i];
    
    for (int i = 0, j = 0, k = 0; k < n1 + n2; k++)
    {
        if (i<n1 && j<n2)
        {
            if(a1[i]>=a2[j])
                newarr[k] = a2[j++];
            else
                newarr[k] = a1[i++];
        }
        else if(i>=n1)
            newarr[k++] = a2[j++];
        else if(j>=n2)
            newarr[k++] = a1[i++];
    }
    return newarr;
}

void mergeSort(int* a, int low, int high){
    // int n = high-low+1;
    int mid = (high + low) / 2;
    if (low==high)
        return;
    mergeSort(a,low,mid);
    mergeSort(a, mid + 1, high);
    merge(a+low,a+mid+1,mid-low+1,high-mid,a+low);
}

void print(int* a, int n){
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main(int argc, char const *argv[])
{
    int arr1[8]={1,4,2,8, 6, 5, 7, 9};
    mergeSort(arr1, 0, 7);
    print(arr1, 8);
    return 0;
}


