#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
 * PROBLEM: Longest Palindrome (LeetCode 409) - OPTIMAL
 * * APPROACH: Hashing / Frequency Counting
 * 1. Count the frequency of every character.
 * 2. If a frequency is even, we can use the whole thing symmetrically.
 * 3. If a frequency is odd, we can use the even portion of it (freq - 1).
 * 4. We can place exactly ONE leftover odd character in the absolute center.
 * * TIME COMPLEXITY: O(N) - We iterate through the string once, then the map.
 * SPACE COMPLEXITY: O(1) - The map holds at most 52 characters (a-z, A-Z), 
 * which is a constant maximum size.
 */

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mpp;
        
        // Step 1: Count all character frequencies
        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;
        }
        
        int count = 0;
        bool hasOdd = false; // Flag to track if we have a centerpiece
        
        // Step 2: Process the counts
        for (auto ch : mpp) {
            int freq = ch.second; 
            
            if (freq % 2 == 0) {
                // If even, use all of them
                count += freq;
            } else {
                // If odd, use the even portion of it (freq - 1)
                count += (freq - 1);
                // Mark that we have at least one odd character for the center
                hasOdd = true;
            }
        }
        
        // Step 3: Add the single centerpiece if we found any odd characters
        if (hasOdd) {
            count += 1;
        }
        
        return count;
    }
};

// Optional main function for local VS Code testing
int main() {
    Solution sol;
    
    string test1 = "abccccdd";
    cout << "Test 1 (abccccdd): " << sol.longestPalindrome(test1) << " (Expected: 7)" << endl;
    
    string test2 = "aaabbbccc";
    cout << "Test 2 (aaabbbccc): " << sol.longestPalindrome(test2) << " (Expected: 7)" << endl;

    return 0;
}