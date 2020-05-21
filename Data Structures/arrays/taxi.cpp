// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     // int n=10,k=8; 
//     // cin>>n>>k;
//     // int arr[n];
//     // for(int i = 0; i<n;i++)
//     //     cin>>arr[i];
//     // int c = k;
//     // if(arr[k-1]>0){
//     //     while(arr[c-1]==arr[k-1]) 
//     //         c++;
//     //     cout<<--c;
//     // }
//     // else{
//     //     while(arr[c-1]<=0) 
//     //         c--;
//     //     cout<<c;
//     // }
//     string s = "CodeForces";

//     for (int i = 0; i < s.length(); i++)
//     {
//         //AEIOYU
        
//     }
    
//     s.insert(0,".");

//     cout << s;
//     return 0;
// }

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

int main(){
    freopen("array.txt", "r", stdin);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    int cap = 5;
    int b[cap] = { 0 };
    int taxi = 0;
    for (int i = 0; i < n; i++)
    {
        b[a[i]]++;
    }
    
    for (int i = 0; i <= cap / 2; i++)
    {
        int x = b[cap - i - 1] - b[i];
        if (x >= 0)
            {   
                if(cap-1-i==i)
                    {
                        taxi = taxi + (b[i] * i) / (cap - 1);
                        b[i] = ((b[i] * i) % (cap - 1))/i;
                    }
                else
                    {
                        taxi = taxi + b[cap - i - 1];
                        b[cap - i - 1] = 0;
                        b[i] = 0;    
                    }
            }
        else{
                taxi = taxi + b[cap - i- 1];
                b[cap - i - 1] = 0;
                b[i] = -1*x;
        }
    }
    // printArray(b, 5);
    int t = cap -1;
    cap--;
    
    // 0 x 1 0 0 -> x/4 + 2/4+ 1 or x/4 + 2/4
    // 0 x 0 0 0 -> x/4 + 1 or x/4

    // for (int i = 0; i <= (t+1) / 2; i++)
    // {
    //     int x = b[i] * i;
    //     int f = t - cap + x;
    //     taxi = taxi + f / t;
    //     cap = (x / t + 1) * t - x;
    //         }        
    //     else {
    //         cap = cap - x;
            
    //         }
    // }
    // if(cap<4 && cap>=0) taxi += 1;

    taxi = taxi + b[1] / 4;
    if((2 * b[2] + b[1] % 4)%4 !=0)
        taxi++;
    taxi += (2 * b[2] + b[1] % 4) / 4;

    cout << taxi;
    return 0;
}