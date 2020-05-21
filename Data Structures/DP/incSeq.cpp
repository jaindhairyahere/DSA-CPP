#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int incSeq(int* a, int n){
    int curr = 0;
    int len = 0;
    int maxlen = len;
    for (int i = 0; i < n; i++)
    {
        if (a[i]>=curr)
        {
            len++;
        }
        else{
            if(maxlen<len)
                maxlen = len;
            len = 1;
        }
        curr = a[i];
    }
    if(maxlen<len)
        maxlen = len;
    return maxlen;
}

int main(int argc, char const *argv[])
{
    freopen("../arrays/array.txt", "r", stdin);
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    cout << incSeq(array, n);
    return 0;
}
