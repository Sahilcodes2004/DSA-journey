// we use a array as a whichere every index is a bucket for a charcter 
//we loop through the first string and increment the charcter bucket for that charcter in the array by 1
// for every charcter of the second string we decrement the charcter bucket for that charcter by 1
// if all the buckets are zero then the strings are anangram
#include<bits/stdc++.h>
#include<string>
using namespace std;
class Solution{
    public:
    bool isanagram(string s,string t)
    { if(s.size()!=t.size()) return false;
        int arr[26]={0};
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]-'a']+=1;
            arr[t[i]-'a']-=1;
        

        }
        for(int i=0;i<26;i++){
            if(arr[i]!=0) return false;
        }
        return true;
    }
};
int main()
{
    Solution obj;
    string str1;
    string str2;
    cout<<"Enter the first string:";
    cin>> str1;
    cout<<"Enter the second string:";
    cin>>str2;
    bool flag=obj.isanagram(str1,str2);
    if(flag==true){
        cout<<"The strings are anagram";

    }
    else{
        cout<<"The strings are not anagram";
    }

    
    return 0;

}
