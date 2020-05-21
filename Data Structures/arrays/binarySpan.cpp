#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

void swap(int &a, int &b);
int longestSpan(int *arr1, int *arr2);
operator-(int *arr1, int *arr2);

int main(int argc, char const *argv[])
{   
    freopen("array.txt", "r", stdin);
    int T =1;
    // cin >> T;
    for (int j = 0; j < T; j++)
    {
        int n;
        cin >> n;
        int array1[n];
        for (int i=0; j<n; j++)
            cin>>array1[i];
        int array2[n];
        for (int i=0; j<n; j++)
            cin>>array2[i];

        longestSpan(array1, array2,n);  
    }
    return 0;
}

int longestSpan(int* arr1,int *arr2, int n){
    int s1 = 0;
    int s2 = 0;
    for (int i = 0; i < n; i++)
    {
        s1 += arr1[i];
        s2 += arr2[i];
    }
    /// s1< s2
    int l = 0, r = 0;
    while(s1!=s2){
        if (arr)
        {
            /* code */
        }
        
    }
}