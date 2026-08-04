#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Base check: If lengths don't match, they can't be isomorphic
        if (s.length() != t.length()) return false;

        // Map 1: Tracks mapping from s[i] -> t[i]
        unordered_map<char, char> mapST;
        
        // Map 2: Tracks mapping from t[i] -> s[i] (prevents two s keys pointing to same t value)
        unordered_map<char, char> mapTS;

        for (int i = 0; i < s.length(); i++) {
            char charS = s[i];
            char charT = t[i];

            // 1. Check if charS was already mapped to a DIFFERENT character in t
            if (mapST.find(charS) != mapST.end()) {
                if (mapST[charS] != charT) {
                    return false;
                }
            } else {
                // If charS is new, record its mapping
                mapST[charS] = charT;
            }

            // 2. Check if charT was already mapped to a DIFFERENT character in s
            if (mapTS.find(charT) != mapTS.end()) {
                if (mapTS[charT] != charS) {
                    return false;
                }
            } else {
                // If charT is new, record its mapping
                mapTS[charT] = charS;
            }
        }

        return true;
    }
};
int main()
{
    Solution obj;
    string s ;
    string t ;
  cout<<"Enter the strings:";
  cin>>s;
  cin>>t;
  cout<<obj.isIsomorphic(s,t);
}