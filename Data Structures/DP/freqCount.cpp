#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    freopen("../arrays/array.txt", "r", stdin);
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    int a[11]={0};
    for (int i = 0; i < n; i++)
        a[array[i]]++;
    for (int i = 0; i < 11; i++)
        cout<<i<<"\t"<<a[i]<<"\n";
    
    return 0;
}
