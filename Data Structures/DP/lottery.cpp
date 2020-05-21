#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int x;
    cin >> x;
    int a[5] = { 100, 20, 10, 5, 1 };
    int den = 0;
    for (int i = 0; i < 5; i++)
    {
        den = den + x / a[i];
        x = x % a[i];
    }
    cout << den;
    return 0;
}
