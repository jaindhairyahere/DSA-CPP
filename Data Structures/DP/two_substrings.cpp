#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    freopen("../arrays/array.txt", "r", stdin);
    string a;
    cin >> a;
    string x;
    int p = -1;
    int q = -1;
    unsigned int f = 0;
    //ABAXXAB   
    while(f < a.length())
    {
        if (a.substr(f, 2) == "AB") {
            if(p<0) p = f+1;
            
                if(q>0 && (f-q>=1)){
                    cout<<"Yes";
                    p = 1000;
                    break;
                
            }
        }//ABABAB
        else if (a.substr(f, 2) == "BA"){
            if(q<0) q = f+1;
            
                if(p>0 && (f-p>=1)){
                    cout<<"Yes";
                    p = 1000;
                    break;
                
            }
        }
        f++;
    }
    if(p!=1000)
        cout << "No";
    return 0;
}
