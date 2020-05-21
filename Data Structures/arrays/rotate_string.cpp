#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> arr;
    string s = "I.am.Dhairya.Jain";
    // getline(cin,s);
    char cstr[s.size()+1];
    s.copy(cstr, s.size());
    cstr[s.size()] = '\0';
    // cout << cstr;
    char *psh;
    psh = strtok(cstr, ".");
    while (psh!=NULL)
    {
        arr.push_back(psh);
        psh = strtok(NULL,".");
    }
    for (vector<string>::iterator i = arr.end() - 1; i != arr.begin()-1; i--)
    {
        cout << *i << ".";
    }

    return 0;
}
