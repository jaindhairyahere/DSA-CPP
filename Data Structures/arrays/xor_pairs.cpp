#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    string a = "%d";
    int n;
    freopen("xor_pairs.txt", "r", stdin);
    cin >> n;
    vector<int> array(n,0);   
    for (int i = 0; i < n; i++)
        cin >> array[i];
    sort(array.begin(), array.end());
    int count = 0;
    size_t i = 0;
    int k = 1;
    // 1 1 1 2 3 3 4 4 5 6 6 6
    while (i < array.size())
    {
        if (array[i + 1] == array[i])
        {
            k += 1;
        }
        else{
            count = count + k * (k - 1) / 2;
            k = 1;
        }
        i++;
    }
    cout << count;
    return 0;
}
