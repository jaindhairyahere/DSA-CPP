#include<bits/stdc++.h>
using namespace std;

void printArray(int* array, int n){
    for (int i = 0; i < n; i++)
    {
        cout << array[i]<<" ";
    }
    cout << "\n";
    return;
}

int main(int argc, char const *argv[])
{

    freopen("../arrays/array.txt", "r", stdin);
    int n,k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    int score[n];
    score[0] = arr[0];
    score[1] = score[0] + arr[1];
    int s = 0;
    for (int i = 2; i < n; i++)
    {
        for (int t = 1; t<= k; t++)
        {   if(i<t) continue;
            s = score[i - 1];
            s = max(s, score[i - t]);
        }
        score[i] = arr[i] + s;
    }
    cout << score[n - 1];
    return 0;
}
