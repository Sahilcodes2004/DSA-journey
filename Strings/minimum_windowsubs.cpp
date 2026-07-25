#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

/*
 * PROBLEM: Minimum Window Substring (LeetCode 76) - OPTIMAL
 * APPROACH: Dynamic Sliding Window (Two Pointers + Count Tracking)
 *
 * LOGIC:
 * 1. Build a target frequency map (target[128]) for characters in string 't'.
 * 2. Track 'count' = t.size() representing total character occurrences still needed.
 * 3. Expand 'right':
 * - If s[right] is needed (target[s[right]] > 0), decrement 'count'.
 * - Decrement target[s[right]]--.
 * 4. Shrink 'left' while count == 0 (Valid Window):
 * - Update min_length and start_index if current length (right - left + 1) is smaller.
 * - Increment target[s[left]]++.
 * - If target[s[left]] > 0, it means we dropped a required character, so increment 'count++'.
 * - Move left++.
 *
 * TIME COMPLEXITY: O(N) - Both pointers only move forward across string 's'.
 * SPACE COMPLEXITY: O(1) - Fixed 128-slot ASCII array.
 */

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) return "";

        int target[128] = {0};
        for (char c : t) {
            target[c]++;
        }

        int left = 0;
        int count = t.size(); // Total character matches needed
        int min_length = INT_MAX;
        int start_index = -1;

        for (int right = 0; right < s.size(); right++) {
            char right_char = s[right];

            // If this character is needed for string 't', decrement remaining needed count
            if (target[right_char] > 0) {
                count--;
            }

            // Reduce count in target map (non-needed chars will go negative)
            target[right_char]--;

            // When count == 0, current window [left...right] contains all characters of 't'
            while (count == 0) {
                int current_len = right - left + 1;
                if (current_len < min_length) {
                    min_length = current_len;
                    start_index = left;
                }

                char left_char = s[left];
                target[left_char]++;

                // If target count goes above 0, we just dropped a required character!
                if (target[left_char] > 0) {
                    count++; // Window is no longer fully valid, break while loop
                }

                left++;
            }
        }

        if (start_index == -1) return "";
        return s.substr(start_index, min_length);
    }
};

int main() {
    Solution sol;
    cout << "Test 1: " << sol.minWindow("ADOBECODEBANC", "ABC") << " | Expected: BANC\n";
    cout << "Test 2: " << sol.minWindow("a", "a") << " | Expected: a\n";
    cout << "Test 3: " << sol.minWindow("a", "aa") << " | Expected: (empty)\n";
    return 0;
}