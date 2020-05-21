#include<bits/stdc++.h>
using namespace std;

int solve(int y, int* t, int* h, int* dir, int n){
    if(y==n-1)
        return 1;
    if (t[y] - t[y - 1] > h[y] + max(dir[y - 1], 0) * h[y - 1])
        dir[y] = -1;
    else if(t[y+1] + min(dir[y+1],0)*h[y+1] > t[y] + h[y])        
        dir[y] = 1;
    if(dir[y]!=0)
        return 1 + solve(y + 1, t, h, dir, n);
    return solve(y + 1, t, h, dir, n);
}

int main(int argc, char const *argv[])
{
    freopen("../arrays/array.txt", "r", stdin);
    int n;
    cin >> n;
    int trees[n] = {0};
    int heights[n] = {0};
    int dir[n] = {-1};
    dir[n - 1] = 1;
    for (int i = 0; i < n; i++)
        cin >> trees[i] >> heights[i];
    if(n>=0 && n<=2){
        cout<<n;
        return 0;
    }
    cout << 1 +solve(1, trees, heights, dir, n);
    return 0;
}
