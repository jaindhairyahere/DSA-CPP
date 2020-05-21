#include<bits/stdc++.h>
using namespace std;

void print(int* arr, int n, int size){
    for (int i = 0; i < n; i++)
        {for (int j = 0; j < n; j++)
            {
                cout << *(arr+i*size+j)<< " ";                
            }
        cout << endl;
        }
}

void swap(int& a,int& b){
    int t = a;
    a = b;
    b = t;
}

int rightIndex(int i, int n, int size){
    return (n-1 + size*i);
}

int oppIndex(int i,int n,int size){
    return (size * (n - 1) + n - i-1);
}

int leftIndex(int i, int n,int size){
    return (size*(n-1-i));
}
void rotateL(int* arr, int level, int size){ 
    for (int i = 0; i < level - 1; i++)
    {
        swap(*(arr+i), *(arr+ rightIndex(i,level,size)));
        swap(*(arr + i), *(arr + oppIndex(i,level,size)));
        swap(*(arr+i), *(arr + leftIndex(i,level,size)));
    }
}
void  rotate(int* arr, int n){
    for (int i = n,j=n; i >= 1; i=i-2,j--)
        rotateL(arr+(n+1)*(n-j), i,n);
}
int main(int argc, char const *argv[])
{
    freopen("array.txt", "r", stdin);
    int T = 1;
    // cin >> T;
    for (int j = 0; j < T; j++)
    {
        int n;
        cin >> n;
        int array[n][n];
        for (int i=0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin>>array[i][j];
        
        // print(&array[0][0], n, n);
        rotate(&array[0][0], n);
        print(&array[0][0], n, n);
    }
    return 0;
}
