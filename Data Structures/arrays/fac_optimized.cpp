#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

#define size 500

int* multiply(int a, int* b, int* bs){
    int carry = 0;
    int i = 0;
    for ( i = 0; i < *bs; i++)
    {
        int j = a * b[size-i-1] + carry;
        carry = j / 10;
        b[size - i-1] = j % 10;
    }
    while (carry!=0)
    {
        b[size - i-1] = carry % 10;
        carry = carry / 10;
        i++;
        *bs = *bs + 1;
    }
    return b;
}

void factorial(int n){
    int i = 2;
    int fact[size] = {0};
    fact[size - 1] = 1;
    int digits = 1;
    while (i <= n)
    {
        multiply(i,fact,&digits);
        i++;
    }
    for (int i = digits-1; i > -1; i--)
    {
        cout << fact[size - i - 1];
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    // Fact N contains digit < digits in N^N i.e. N*log10 N + 1
    factorial(100);
    return 0;
}