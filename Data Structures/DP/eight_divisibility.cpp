#include<bits/stdc++.h>
using namespace std;

int operator%(const vector<int> &v, const int& b){
    int n = v.size();
    if (n>= 3)
        return (v[n - 3] * 100 + v[n - 2] * 10 + v[n - 1]) % b; 
    else{
        if(n==2) return (v[n - 2] * 10 + v[n - 1]) % b;
        else if(n==1) return (v[n - 1]) % b;
        else
            return -1;
    }
}


int search(int n, vector<int> arr){
    if(arr%8 == 0) {
            cout << "YES\n";
            for (auto &&i : arr)
                cout << i;
            return 1;}
    for (int b = (1<<n)-1; b >= 0; b--){
        vector<int> subset;
        for (int i = 0; i < n; i++)       
            if(b&(1<<i)) 
                subset.push_back(arr[i]);
        if(subset%8 == 0) {
            cout << "YES\n";
            for (auto &&i : subset)
                cout << i;
            return 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    freopen("../arrays/array.txt", "r", stdin);
    vector<int> number;
    char i;
    while (cin.get(i))
        {if(i==' ' || i=='\n')
            break;
    number.push_back(i - '0');}
    if(!search(number.size(), number)) cout<<"NO";
    return 0;
}
