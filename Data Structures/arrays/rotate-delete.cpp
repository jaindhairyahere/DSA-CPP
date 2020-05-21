#include<iostream>
using namespace std;


int operation(int*a,int n){
    //1 2 3 4 5 -> 3
    //1 2 3 4 5 6 -> 3
    //3 4 5 6 1 - 2
    //4 6 1 3 - 5
    //6 3 4 - 1
    //3 4 - 6
    //3  - 3
    int deleted = 0;
    int count = 1; // k -1 from begin
    int index = count;
    // int index = (n - 1 - count)%n;
    while (count <= n-1 )
    {
        if (a[index]!=-1)
        {
            cout << a[index] << " "<< index<<endl;
            a[index] = -1;
            deleted++;
            count++;
            index = (count + index + 1) % n;
            
        }
        else
        {
            index = (n + index - deleted)%n;
        }
    }
    cout << endl;
    return a[index];
}

int main(int argc, char const *argv[])
{
    int array[6] = {1, 2, 3, 4, 5, 6};
    cout<< operation(array, 6);
    return 0;
}
