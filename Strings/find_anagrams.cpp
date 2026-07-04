#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * PROBLEM: Find All Anagrams in a String (LeetCode 438)
 * PATTERN: Fixed Sliding Window + Frequency Array
 * TIME COMPLEXITY: O(N)
 * SPACE COMPLEXITY: O(1) - The two 26-slot arrays take constant memory.
 */

class Solution {
public:
    bool checkMatch(int sc1[], int sc2[]) {
        for (int i = 0; i < 26; i++) {
            if (sc1[i] != sc2[i]) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.size() < p.size()) return ans;

        int sc1[26] = {0}; // Window scoreboard
        int sc2[26] = {0}; // Target scoreboard

        // Setup the first window
        for (int i = 0; i < p.size(); i++) {
            sc2[p[i] - 'a'] += 1;
            sc1[s[i] - 'a'] += 1;
        }
        
        if (checkMatch(sc1, sc2)) ans.push_back(0);
        
        // Sliding Window Engine
        for (int i = p.size(); i < s.size(); i++) {
            sc1[s[i] - 'a'] += 1;               // Add right edge
            sc1[s[i - p.size()] - 'a'] -= 1;    // Remove left edge
            
            if (checkMatch(sc1, sc2)) {
                ans.push_back(i - p.size() + 1);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> result = sol.findAnagrams(s, p);
    
    cout << "Anagram indices: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;
    
    return 0;
}