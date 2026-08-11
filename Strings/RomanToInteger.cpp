#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mpp;
        vector<char> chars = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        vector<int> values = {1, 5, 10, 50, 100, 500, 1000};
        
        // 1. Build the map
        for(int i = 0; i < chars.size(); i++) {
            mpp[chars[i]] = values[i];
        }
        
        int ans = 0;
        
        // 2. Loop through all characters EXCEPT the last one
        for(int i = 0; i < s.size() - 1; i++) { 
            if(mpp[s[i]] >= mpp[s[i+1]]) {
                ans += mpp[s[i]];
            }
            else {
                ans -= mpp[s[i]]; // Subtract current value if smaller than next
            }
        }
        
        // 3. Always add the very last character
        ans += mpp[s[s.size() - 1]];
        
        return ans;
    }
};

// Main function for local testing in VS Code
int main() {
    Solution sol;
    
    // Test Case 1
    string s1 = "III";
    cout << "Input:  \"" << s1 << "\"\n";
    cout << "Output: " << sol.romanToInt(s1) << " (Expected: 3)\n\n";

    // Test Case 2
    string s2 = "LVIII";
    cout << "Input:  \"" << s2 << "\"\n";
    cout << "Output: " << sol.romanToInt(s2) << " (Expected: 58)\n\n";

    // Test Case 3 (Subtraction test case)
    string s3 = "MCMXCIV";
    cout << "Input:  \"" << s3 << "\"\n";
    cout << "Output: " << sol.romanToInt(s3) << " (Expected: 1994)\n\n";

    return 0;
}