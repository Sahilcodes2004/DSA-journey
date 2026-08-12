#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    // Helper function to count substrings with AT MOST k distinct characters
    long long atMost(string& s, int k) {
        if (k < 0) return 0;
        
        int hash[26] = {0};
        int left = 0, right = 0;
        int distinct = 0;
        long long count = 0;
        
        while (right < s.size()) {
            // Add the current character to our window
            if (hash[s[right] - 'a'] == 0) {
                distinct++;
            }
            hash[s[right] - 'a']++;
            
            // If we have more than k distinct characters, shrink the window from the left
            while (distinct > k) {
                hash[s[left] - 'a']--;
                if (hash[s[left] - 'a'] == 0) {
                    distinct--;
                }
                left++;
            }
            
            // Add all valid substrings ending at 'right'
            count += (right - left + 1);
            right++;
        }
        
        return count;
    }

public:
    long long countSubstr(string s, int k) {
        // EXACTLY k = (AT MOST k) - (AT MOST k - 1)
        return atMost(s, k) - atMost(s, k - 1);
    }
};

// Main function for local testing in VS Code
int main() {
    Solution sol;
    
    // Test Case 1
    string s1 = "abc";
    int k1 = 2;
    cout << "Input:  s = \"" << s1 << "\", k = " << k1 << "\n";
    cout << "Output: " << sol.countSubstr(s1, k1) << " (Expected: 2)\n\n";

    // Test Case 2
    string s2 = "aba";
    int k2 = 2;
    cout << "Input:  s = \"" << s2 << "\", k = " << k2 << "\n";
    cout << "Output: " << sol.countSubstr(s2, k2) << " (Expected: 3)\n\n";

    // Test Case 3
    string s3 = "aa";
    int k3 = 1;
    cout << "Input:  s = \"" << s3 << "\", k = " << k3 << "\n";
    cout << "Output: " << sol.countSubstr(s3, k3) << " (Expected: 3)\n\n";

    return 0;
}