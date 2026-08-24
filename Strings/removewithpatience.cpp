#include<bits/stdc++.h>
using namespace std;
string fun(string s,string r)
{
    int len =r.size();
    while(true)
    {
        int ind=s.find(r);
        if(ind ==string::npos)
        {
            break;
        }
        if(ind==0)
        {
            s.erase(ind,len);
        }
        else{
            char ch=s[ind-1];
            string x(len,ch);
            s.replace(ind,len,x);
        }
    }
    return s;
}
int main()
{
    string s,r;
    cin>>s>>r;
    cout<<fun(s,r);
    return 0;
}