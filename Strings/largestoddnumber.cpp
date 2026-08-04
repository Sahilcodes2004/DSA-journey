#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        int high=num.length()-1;
        string ans="";
        while(high>=0)
        {
            char c=num[high];
            int x=c-'0';
            if(x%2==0){
                high--;
            }
            else{
                ans+=num.substr(0,high+1);
                break;
            }
        }
        return ans;
        
    }
};
int main()
{
      string s;
    Solution obj;
    cout<<"Enter the string:";
  
    cin>>s;
    cout<<obj.largestOddNumber(s);
    return 0;

}