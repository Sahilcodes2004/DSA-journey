#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        
        int max_freq=0;
        int max_length=0;
        int hashar[26]={0};
        for(int right=0;right<s.length();right++)
        { hashar[s[right]-'A']++;
        max_freq=max(max_freq,hashar[s[right]-'A']);
        int cur_len=right-left+1;
        while(right-left+1-max_freq>k)
        {
            hashar[s[left]-'A']--;
            left++;
                    }
                    max_length=max(max_length,right-left+1);

        }
        return max_length;
        
    }
};
int main()
{
    Solution obj;
    string s;
    cout<<"Enter your string";
    cin>>s;
    int k;
    cout<<"Enter the value of k";
    cin>>k;
    int max_length=obj.characterReplacement(s,k);
    cout<<"Maximum length of substring with repeating charcaters is"<<max_length;
    return 0;
}