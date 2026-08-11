#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int count = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count++;
                maxi = max(count, maxi);
            } 
            else if (s[i] == ')') {
                count--;
            }
        }
        return maxi;
    }
};

// Main function for local testing in VS Code
int main() {
    Solution sol;
    
    // Test Case 1
    string s1 = "(1+(2*3)+((8)/4))+1";
    cout << "Input:  \"" << s1 << "\"\n";
    cout << "Output: " << sol.maxDepth(s1) << " (Expected: 3)\n\n";

    // Test Case 2
    string s2 = "(1)+((2))+(((3)))";
    cout << "Input:  \"" << s2 << "\"\n";
    cout << "Output: " << sol.maxDepth(s2) << " (Expected: 3)\n\n";

    // Test Case 3
    string s3 = "()(())((()()))";
    cout << "Input:  \"" << s3 << "\"\n";
    cout << "Output: " << sol.maxDepth(s3) << " (Expected: 3)\n\n";

    return 0;
}