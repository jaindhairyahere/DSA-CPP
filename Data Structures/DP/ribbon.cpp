
#include<bits/stdc++.h>
using namespace std;

int cut(bool* ready, int* value, int* cuts, int n){
    if(ready[n])
        return value[n];
    if(n==0){
        return 0;}
    if(n<0)
        return -1000;
    int best = -1000;
    for (int i = 0; i < 3;i++)
    {
        best = max(best, cut(ready, value, cuts, n-cuts[i])+1);
    }
    value[n] = best; ready[n] = 1;
    return best;
}

int main(int argc, char const *argv[])
{
    freopen("../arrays/array.txt", "r", stdin);
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    bool ready[n+2] = {0};
    for (auto &&i : ready)
        i = 0;

    int value[n+1] = {0};
    int cuts[3] = {a, b, c};
    sort(cuts, cuts + 2);
    cout << ready[n];
    cout << cut(ready, value, cuts, n);
    return 0;
}
