#include<bits/stdc++.h>
using namespace std;
void print(int* a, int n){
    for (int i = 0; i < n; i++) cout << a[i];
    cout << "\n";
}

int main(int argc, char const *argv[])
{
    freopen("../arrays/array.txt", "r", stdin);
    int d,sum;
    cin >> d >> sum;
    if(sum>9*d || (d>1&&sum<=0)) {
        cout << -1 << " " << -1;
        return 0;
    }
    if(d==1 && sum==0)
        {cout << 0 << " " << 0;
            return 0;
        }
    int mini[d] = {1}, maxi[d] = {1};
    int s = 1;
    int i = 0;
    while (s < sum)
    {

        mini[d - i - 1] +=1;
        if(s>=9 + 9*i)
            i++;
        maxi[i] += 1;
        s++;
    }
    print(mini, d);
    print(maxi, d);
    return 0;
}
