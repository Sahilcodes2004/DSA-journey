#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(),strs.end());
        string x=strs[0];
        string y=strs[strs.size()-1];
        int i =0;
        string ans="";
        while(i<x.size()&&i<y.size())
        {
            if(x[i]==y[i]){
                ans+=x[i];
                i++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};
int main()
{
    Solution obj;
    int n;
    cin>>n;
    vector<string>strs(n);
    for(int i=0;i<n;i++)
    {
        cin>>strs[i];
    }
   string ans=obj.longestCommonPrefix(strs);
    cout<<ans;
    return 0;
}