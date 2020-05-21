#include<iostream>
#include<vector>
#include<string>
using namespace std;
void trim(string& s){
    int natural = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]!='0')
        {
            natural = i;
            break;
        }
    }
    s = s.substr(natural);
}
void equalize(string& a, string& b){
    int lenA = a.length();
    int lenB = b.length();
    string c = b;
    if (lenA >= lenB)
    {
        b = "";
        for (int i = 0; i < lenA-lenB; i++) 
            b.push_back('0'); 
        for (int i = 0; i < lenB; i++)
        {
            b.push_back(c[i]);
        }
    }
    else
    {
        equalize(b, a);
    }
}

void reverse(string &a){
    char temp;
    for (int i = 0; i < a.size()/2; i++)
    {
        temp = a[a.size()-i-1];
        a[a.size() - 1-i] = a[i];
        a[i] = temp;
    }
}

string addStr(string a, string b){
    equalize(a, b);
    int lenA = a.length();
    int lenB = b.length();
    string answer = "";
    vector<int> iBuffer;
    for (int i = max(lenA,lenB) - 1; i >-1 ; i--)
    {
        // if()
        int r = a[i] + b[i] - '0' - '0';
        if (iBuffer.size() == 1) {
            r += iBuffer.at(0) - '0';
            iBuffer.pop_back();
        }

        answer.push_back(r%10 + '0');
        iBuffer.push_back(r / 10 + '0');
    }
    reverse(answer);
    return answer;
}
string operator+(const string a, const string b){ return addStr(a, b);}
string sum(string* v,int lenB){
    if(lenB==1)
        return *v;
    return addStr(v[0],sum(v+1,lenB-1));
}
string multiply(string a, string b){
    int lenA = a.length();
    int lenB = b.length();
    if(lenA < lenB)
        return multiply(b, a);
    string sBuffer[lenB];
    for (int i = lenB- 1; i > -1; i--)
    {
        string answer = "";
        vector<int> iBuffer;
        for (int j = lenA - 1; j > -1; j--)
        { 
            int r = (a[j]- '0') * (b[i]  - '0');
            if (iBuffer.size() == 1) {
                r += iBuffer.at(0) - '0';
                iBuffer.pop_back();
                }
            answer.push_back(r%10 + '0');
            if (r/10 >0)
                iBuffer.push_back(r / 10 + '0');
            if(j==0)
                answer.push_back(r / 10 + '0');
        }
        reverse(answer);
        for (int k = 0; k < lenB - 1 - i; k++)
        {
        answer.push_back('0');
        }
        sBuffer[i] = answer;
        // cout << rev_ans << endl;
    }
    return sum(sBuffer,lenB);
}
string operator*(const string a, const string b){ return multiply(a, b);}
string factorial(int n){
    int i = 1;
    string fact = "1";
    while (i <= n)
    {
        fact = fact * to_string(i);
        i++;
    }
    trim(fact);
    return fact;
}
int main(int argc, char const *argv[])
{
    // cout << "Enter The Number to Get Factorial : ";
    // int n;
    // cin >> n;
    string test = "hello";
    reverse(test);
    cout << factorial(6) << endl;
    return 0;
}