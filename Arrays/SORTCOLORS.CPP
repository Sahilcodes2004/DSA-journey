#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * PROBLEM: Sort Colors (LeetCode 75)
 * * PATTERN: Three Pointers / Dutch National Flag Algorithm
 *
 * STATEMENT:
 * Given an array 'nums' with n objects colored red, white, or blue, 
 * sort them in-place so that objects of the same color are adjacent, 
 * with the colors in the order red, white, and blue.
 * 
 * We will use integers 0, 1, and 2 to represent the colors red, white, and blue respectively.
 * You must solve this problem WITHOUT using the library's sort function.
 *
 * GOAL:
 * Achieve O(N) Time Complexity and O(1) Space Complexity in a single pass!
 *
 * HINT FOR THREE POINTERS:
 * - 'low' tracks the boundary where 0s should go (starts at index 0).
 * - 'mid' scans through the array from left to right (starts at index 0).
 * - 'high' tracks the boundary where 2s should go (starts at last index).
 *
 * RULES AS 'mid' MOVES:
 * 1. If nums[mid] == 0: swap(nums[low], nums[mid]), then low++, mid++
 * 2. If nums[mid] == 1: just mid++
 * 3. If nums[mid] == 2: swap(nums[mid], nums[high]), then high-- (do NOT increment mid here!)
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // TODO: Write your solution logic here!
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            // Your logic goes here
        }
    }
};

// Main function for local VS Code testing
int main() {
    Solution sol;
    
    vector<int> test1 = {2, 0, 2, 1, 1, 0};
    cout << "Before sort: 2 0 2 1 1 0\n";
    sol.sortColors(test1);
    cout << "After sort:  ";
    for (int num : test1) cout << num << " ";
    cout << "\n(Expected:   0 0 1 1 2 2)\n\n";

    vector<int> test2 = {2, 0, 1};
    cout << "Before sort: 2 0 1\n";
    sol.sortColors(test2);
    cout << "After sort:  ";
    for (int num : test2) cout << num << " ";
    cout << "\n(Expected:   0 1 2)\n";

    return 0;
}