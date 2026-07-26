#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * PROBLEM: Sort Colors (LeetCode 75)
 * PATTERN: Dutch National Flag Algorithm (1-Pass, 3 Pointers)
 * 
 * POINTER INVARIANTS:
 * - [0 ... low - 1]   : All 0s
 * - [low ... mid - 1] : All 1s
 * - [mid ... high]    : Unexamined elements (unknown)
 * - [high + 1 ... N-1]: All 2s
 * 
 * TIME COMPLEXITY: O(N) - Single pass through the array.
 * SPACE COMPLEXITY: O(1) - Constant space in-place swaps.
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                // Case 1: Found a 0 -> Swap with low, then advance low and mid
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } 
            else if (nums[mid] == 1) {
                // Case 2: Found a 1 -> 1s stay in the middle, just advance mid
                mid++;
            } 
            else {
                // Case 3: Found a 2 -> Swap with high, shrink high boundary
                // Note: Do NOT increment mid here because the newly swapped 
                // element from 'high' hasn't been checked yet!
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> test = {2, 0, 2, 1, 1, 0};
    
    sol.sortColors(test);
    
    cout << "Sorted Array: ";
    for (int num : test) {
        cout << num << " ";
    }
    cout << "\nExpected:     0 0 1 1 2 2" << endl;
    
    return 0;
}