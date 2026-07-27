#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        int balance =0;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
           if(s[i]=='('){
           
           
           if(balance>0&&s[i]=='(')
           {
            ans+=s[i];

           }
           balance++;
           }
            else if(s[i]==')'){
            balance--;
            if(balance>0)
            {
            ans+=s[i];
            
           }
           }
        
           
           
        }
        return ans;
        
    }
};
int main()
{
    Solution obj;
    string s;
    cout<<"Enetr the string";
    cin>>s;
    string ans=obj.removeOuterParentheses(s);
    cout<<ans;
    return 0;

}