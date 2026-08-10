#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp1;
        string ans = "";
        
        // Step 1: Count character frequencies
        for (int i = 0; i < s.size(); i++) {
            mpp1[s[i]]++;
        }
        
        // Step 2: Create buckets where index = frequency
        vector<string> buckets(s.size() + 1, "");
        
        // Step 3: Populate buckets
        for (auto it : mpp1) {
            char c = it.first;
            int freq = it.second;
            buckets[freq].append(freq, c);
        }
        
        // Step 4: Build string from highest frequency down to 1
        for (int i = buckets.size() - 1; i > 0; i--) {
            if (!buckets[i].empty()) {
                ans += buckets[i];
            }
        }
        
        return ans;
    }
};

// Main function for local testing in VS Code
int main() {
    Solution sol;
    
    // Test Case 1
    string s1 = "tree";
    cout << "Input:  \"" << s1 << "\"\n";
    cout << "Output: \"" << sol.frequencySort(s1) << "\"\n\n";

    // Test Case 2
    string s2 = "cccaaa";
    cout << "Input:  \"" << s2 << "\"\n";
    cout << "Output: \"" << sol.frequencySort(s2) << "\"\n\n";

    // Test Case 3
    string s3 = "Aabb";
    cout << "Input:  \"" << s3 << "\"\n";
    cout << "Output: \"" << sol.frequencySort(s3) << "\"\n\n";

    return 0;
}