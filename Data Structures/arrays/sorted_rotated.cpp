// #include<iostream>
// #include<stdio.h>
// #include<vector>
// #include<string>
// using namespace std;

// ostream& operator<<(ostream& stream, const vector<int>& a){
//     for (size_t i = 0; i < a.size(); i++)
//     {
//         stream << a[i] << " ";
//     }
//     return stream;
// }
// bool isEven(int p){
//     if(p%2==0)
//         return true;
//     return false;
// }

// int findPivot(const vector<int>& a){
//     // When n is odd, n/2 is index of last element of left array
//     // When n is even n/2 is length of left array
//     cout << a<<"\t";
//     int n = a.size();
//     int p = a.size() / 2;
//     if (n == 2)
//     {
//         if (a[1] >= a[0])
//             return 1;
//             return 0;
//         }
//     if (n==1 | n==0)
//         return 0;
//     if (a[p] >= a[n - 1])
//     {
//         p = p + findPivot(vector<int>(a.begin() + p, a.end()));
//     }
//     else if(a[p] < a[n-1] && a[0]>a[n-1]){
//         p = findPivot(vector<int>(a.begin(), a.begin() + p));
//     }
//     else{
//         p = n - 1;
//     }
//     return p;
// }

// int main(int argc, char const *argv[])
// {
//     vector<int> array;
//     int n;
//     freopen("array.txt", "r", stdin);
//     cin >> n;
//     array.resize(n);
//     for (int i = 0; i < n; i++)
//         cin >> array[i];
//     cout<<isEven(array.size())<<"\t";
//     cout<<array[findPivot(array)+1]<<endl;
//     return 0;
// }
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;




int findPivot2(int* a, int low, int high){
    int p = (high+ low)/ 2;   //p=5
    
    if(high - low >=0){
    if(high-low==1)
        return p+1;
    if (a[p] >= a[high])
    {
        return findPivot2(a,p,high) ;
    }
    else if(a[p] < a[high] && a[low]>a[high]){
        return findPivot2(a,low,p);
    }
    else
        return 0;
    }
    return -1;
}

int findPivot(int* a, int low, int high){
    int n = high - low +1; //n=10
    int p = n/ 2;   //p=5
    if(n==2)
        {if (a[1]>=a[0])
            return 1;
            return 0;
        }
    if (n==1 | n==0)
       return 0;
    if (a[low + p] >= a[low + n - 1])
    {
        p =  p + findPivot(a,low+p,low+n-1) ;
    }
    else if(a[low+p] < a[low+n-1] && a[low]>a[low+n-1]){
        p = findPivot(a,low,low+p-1);
    }
    else{
        p = 0;
    }
    return p;
}
int binary_search(int* arr,int low, int high, int e){
    /* Finds Element e in given array a.
        Returns index if found
        Returns -1 otherwise*/

    int mid = (high + low) / 2;
    if(high-low+1>=1){    
    if (arr[mid]==e) return mid;
    else if (e < arr[mid]){
        return binary_search(arr, low, mid-1, e);
    }
    else
        return binary_search(arr, mid+1, high, e);}
    return -1;
}

string given_sum(int* arr,int n,int sum){
    string result;
    int min_index = findPivot(arr, 0, n - 1)+1;
    int l = min_index%n;
    int r = (n + n - 1 - min_index)%n;
    int s = arr[l] + arr[r];
    int iter = 0;
    // [1, 2,3,5,6,8,10,19,23,48] => 25
    while(iter<=n ){
    if (sum<s) r = (n+r-1)%n;
    else if (sum>s) l = (l+1)%n;
    else {
        result.push_back(l + '0');
        result.push_back(',');
        result.push_back(r + '0');
        return result;
    }
    s = arr[l] + arr[r];
    iter++;
    }
    return "Not Found";
}

int Search(int* a, int low, int high, int e){
    int min_index = findPivot(a, low, high)+1;
    int l = binary_search(a, low, min_index-1, e);
    if(l!=-1)
            return l;
    int r = binary_search(a, min_index, high, e);
    if(r!=-1)
            return r;
    return -1;
}


int main(int argc, char const *argv[])
{
    freopen("array.txt", "r", stdin);
    int size;
    cin >> size;
    int array[size];
    for (int i = 0; i < size; i++)
        cin >> array[i];
    // cout << findPivot2(array, 0, size - 1);
    // cout << binary_search(array, 0, size - 1, 10);
    cout << given_sum(array, size, 60);
    // cout << Search(array,0,size-1,1);
    return 0;
}
