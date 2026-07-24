#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * PROBLEM: Contains Duplicate II (LeetCode 219)
 * * APPROACH: Hash Map (Tracking the most recent index)
 * 1. Use an unordered_map to store the number as the key and its MOST RECENT index as the value.
 * 2. As we iterate through the array, check if the current number is already in the map.
 * 3. If it is, check if the distance between the current index (i) and the stored index is <= k.
 * 4. CRUCIAL: Always update the map with the current index (mpp[nums[i]] = i). 
 * Do NOT put this inside an 'else' block, otherwise the map will hold a "stale" index 
 * and might miss valid pairs later in the array.
 * * TIME COMPLEXITY: O(N) - Single pass through the array. Map lookups/insertions are O(1) average.
 * SPACE COMPLEXITY: O(N) - In the worst case, we store every unique number in the map.
 */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            // If the element is already in the map, check the distance
            if (mpp.find(nums[i]) != mpp.end()) {
                if (i - mpp[nums[i]] <= k) {
                    return true;
                }
            }
            
            // ALWAYS update the map with the most recently seen index
            // (This prevents the "stale index" trap!)
            mpp[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1, 2, 3, 1};
    int k1 = 3;
    cout << "Test 1: " << (sol.containsNearbyDuplicate(nums1, k1) ? "true" : "false") << " (Expected: true)\n";

    vector<int> nums2 = {1, 0, 1, 1};
    int k2 = 1;
    cout << "Test 2: " << (sol.containsNearbyDuplicate(nums2, k2) ? "true" : "false") << " (Expected: true)\n";

    // The tricky test case!
    vector<int> nums3 = {1, 2, 3, 1, 1};
    int k3 = 1;
    cout << "Test 3: " << (sol.containsNearbyDuplicate(nums3, k3) ? "true" : "false") << " (Expected: true)\n";

    return 0;
}