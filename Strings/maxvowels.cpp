#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
 * PROBLEM: Maximum Number of Vowels in a Substring (LeetCode 1456)
 * PATTERN: Fixed Sliding Window
 * TIME COMPLEXITY: O(N)
 * SPACE COMPLEXITY: O(1)
 */

class Solution {
public:
    bool isvowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int countvowels = 0;
        int maxi = 0;
        
        // Setup the first window
        for(int i = 0; i < k; i++) {
            if(isvowel(s[i])) {
                countvowels++;
            }
        }
        maxi = countvowels;
        
        // Sliding Window Engine
        for(int i = k; i < s.size(); i++) {
            if(isvowel(s[i])) {
                countvowels++;
            }
            if(isvowel(s[i - k])) {
                countvowels--;
            }
            maxi = max(maxi, countvowels);
        }
        
        return maxi;
    }
};

int main() {
    Solution sol;
    string s = "abciiidef";
    int k = 3;
    
    cout << "Maximum vowels in a window of size " << k << ": " 
         << sol.maxVowels(s, k) << endl;
         
    return 0;
}