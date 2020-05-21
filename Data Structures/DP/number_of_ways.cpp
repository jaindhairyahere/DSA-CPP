#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    freopen("../arrays/array.txt", "r", stdin);
    int n;
    cin >> n;
    long int arr[n];
    long int sum[n] = {0};
    cin >> arr[0];
    sum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
        }
    if(sum[n-1]%3 != 0 || n==2){
        cout << 0;
        return 0;
    }
    long int t = sum[n-1] / 3;
    int l = 1, r = n - 2; //Middle Array is [l,r] inclusive or l and r indexes

    long long int count = 0;
    while(sum[l-1]!=t && l<n)
            l++;
    while(sum[r]!=2*t && r>0)
            r--;
    cout << l << " " << r << "\n";
    if(r<l){
        cout << 0;
        return 0;
    }
    int l0 = l;
    int ready[r - l + 1] = {0};
    long long int a[r - l + 1]={0};
    while (r >= l)
    {
        if(sum[l-1]==t){
            if(ready[l-l0]==1){
                count += a[l++-l0];
                continue;
            }
            for (int i = r; i >= l; i--){
                if(sum[i]==2*t)
                    count++;
                a[i-l0]+=count;
                ready[i - l0] = 1;
            }
                }
        l++;
    }
    cout << count;
    return 0;
}
