#include <iostream>
#include <string>
#include <cctype> // Required for isalnum() and tolower()

using namespace std;

/*
 * PROBLEM: Valid Palindrome (LeetCode 125)
 * * PATTERN: Two Pointers (Opposite Ends)
 * Instead of creating a new reversed string, we place one pointer at the 
 * start and one at the end, moving them inward to meet in the middle.
 * * TIME COMPLEXITY: O(N) - We traverse the string at most once.
 * SPACE COMPLEXITY: O(1) - No extra memory used, just two integer pointers.
 */

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            // Step 1: Skip non-alphanumeric characters from the left
            if (!isalnum(s[left])) {
                left++;
            }
            // Step 2: Skip non-alphanumeric characters from the right
            else if (!isalnum(s[right])) {
                right--;
            }
            // Step 3: Both characters are valid, so compare them
            else {
                // If they don't match (ignoring case), it's not a palindrome
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                // If they do match, move both pointers inward
                left++;
                right--;
            }
        }
        
        // If pointers cross without returning false, the string is a valid palindrome
        return true;
    }
};

// Optional main function for local VS Code testing
int main() {
    Solution sol;
    string test1 = "A man, a plan, a canal: Panama";
    cout << (sol.isPalindrome(test1) ? "True" : "False") << endl; // Expected: True
    return 0;
}