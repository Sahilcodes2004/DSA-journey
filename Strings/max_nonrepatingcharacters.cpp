#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        int right, left = 0;
        int arr[256] = {0};
         for (int right = 0; right < s.size(); right++) {
            arr[s[right]]++;
        
            
            if (arr[s[right]] == 2) {
                while (arr[s[right]] > 1) {
                    arr[s[left]]--;
                    left++;
                }
            }
             int   count = right - left + 1;
             maxi = max(maxi, count);
        }

        return maxi;
    }
};
int main()
{
    Solution obj;
    string s;
    cout<<"Enter the string";
    cin>>s;
   int maxlength=obj.lengthOfLongestSubstring(s);
   cout<<"The maximun length with non repeating characters is:"<<maxlength;
   return 0;

}