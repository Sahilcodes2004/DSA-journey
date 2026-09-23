#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string isPermutation(const string &s1,const string &s2)
    { vector<int>v1(26,0),v2(26,0);
        for(int i=0;i<s1.size();i++)
        {
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }if(v1==v2)
        {
            return "TRUE";
        }
        for(int i=s1.size();i<s2.size();i++)
        {
            v2[s2[i]-'a']++;
            v2[s2[i-(int)s1.size()]-'a']--;
            if(v1==v2)
            {
                return "TRUE";
            }
        }
        return "FALSE";

    }
};
int main()
{
    Solution obj;
    string s1="ab";
    string s2="auicciay";
    cout<<obj.isPermutation(s1,s2);
    return 0;
}