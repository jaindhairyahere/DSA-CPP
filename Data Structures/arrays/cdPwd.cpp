#include<bits/stdc++.h>
using namespace std;

void pwd(vector<string> v){
    int len = v.size();
    string t = "/";
    // t.resize(64);
    int i = 0;
    while (i < len)
    {
        t += v[i];
        t.push_back('/');
        i++;
    }
    cout << t<<"\n";
}

void cd(vector<string>& v, string p){
    string a = "";
    p.push_back('/');
    // cout << p << " "<< "\n\t";
    // a.capacity();
    if (p[0]=='/')
        v.clear();

    for (unsigned int i = 0; i < p.length(); i++)
    {
        if(p[i]!='/') 
            a.push_back(p[i]);
        else    
        {
            if(a=="..")
                {v.pop_back();}
            else
                if(a.size()>0)
                    v.push_back(a);
            a.clear();
        }
        // cout << a;
    }
}

int main(int argc, char const *argv[])
{
    freopen("array.txt", "r", stdin);
    vector<string> dir;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s,p;
        cin >> s;
        if(s=="pwd")
            pwd(dir);
        else {
            cin >> p;
            cd(dir, p);
        }
    }

    return 0;
}
