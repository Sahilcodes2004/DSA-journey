#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
 * PROBLEM: Group Anagrams (LeetCode 49)
 * * PATTERN: Hash Maps & String Signatures
 * 1. Iterate through the array of strings.
 * 2. For each string, make a copy and sort it alphabetically. This sorted
 * version (e.g., "aet") becomes our unique "signature" or Key.
 * 3. Push the original string into the unordered_map at that Key.
 * 4. Iterate through the map and push all the grouped vectors into our final answer.
 * * TIME COMPLEXITY: O(N * K log K) where N is number of strings, and K is max length of a string.
 * SPACE COMPLEXITY: O(N * K) to store the map.
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        
        // Step 1 & 2: Create signatures and group the original words
        for (int i = 0; i < strs.size(); i++) {
            string x = strs[i];
            sort(x.begin(), x.end());     // Sort copy to create the signature
            mpp[x].push_back(strs[i]);    // Push original word into the signature's bucket
        }
        
        // Step 3: Extract the grouped anagrams from the map
        vector<vector<string>> ans;
        for (auto x : mpp) {
            ans.push_back(x.second);
        }
        
        return ans;
    }
};

// Main function for local VS Code testing
int main() {
    Solution sol;
    
    // Test Case
    vector<string> test = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    vector<vector<string>> result = sol.groupAnagrams(test);
    
    // Print the results
    cout << "Grouped Anagrams:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}