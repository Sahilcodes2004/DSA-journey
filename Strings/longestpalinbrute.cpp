#include <iostream>
#include <string>

using namespace std;

/*
 * PROBLEM: Longest Palindrome (LeetCode 409) - BRUTE FORCE
 * * APPROACH: "Find a pair and cross it out"
 * 1. Look at each letter. If it's already crossed out ('#'), skip it.
 * 2. Look ahead in the rest of the string to find its first matching partner.
 * 3. When found, add 2 to our max length, cross both letters out by changing
 * them to '#', and stop looking for that specific letter.
 * 4. At the end, if our max length is smaller than the original string, it
 * means we have leftover un-paired letters. Add 1 to put one in the center!
 * * TIME COMPLEXITY: O(N^2) - For every letter, we potentially scan the rest of the string.
 * SPACE COMPLEXITY: O(1) - We modify the string directly without using extra data structures.
 */

class Solution {
public:
    int longestPalindrome(string s) {
        int maxcount = 0;
        int originalSize = s.size();

        for (int i = 0; i < s.size(); i++) {
            // 1. If we already crossed this letter out, skip it!
            if (s[i] == '#') {
                continue;
            }

            // 2. Look ahead for a matching partner
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    maxcount += 2;      // We found a pair! Add 2.
                    s[i] = '#';         // Cross out the first one
                    s[j] = '#';         // Cross out the second one
                    break;              // Stop looking for more partners for s[i]
                }
            }
        }

        // 3. Centerpiece check: Did we leave any letters behind?
        if (maxcount < originalSize) {
            maxcount += 1;
        }

        return maxcount;
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