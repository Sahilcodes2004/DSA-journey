#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;      // Tracks the strength of the current gang on the hill
        int candidate;      // Remembers which number is currently holding the hill
        
        for(int i = 0; i < nums.size(); i++) {
            // Rule 1: The hill is empty. The current number claims it.
            if(count == 0) {
                candidate = nums[i];
                count++;
            } 
            // Rule 2: The next number is from the same gang. Backup arrives!
            else if(nums[i] == candidate) {
                count++;
            } 
            // Rule 3: The next number is from a rival gang. They fight and cancel out.
            else {
                count--;
            }
        }
        
        // Because the problem guarantees a majority element (> N/2), 
        // the largest gang will always have survivors holding the hill at the end.
        return candidate;
    }
};

int main() {
    Solution obj;
    
    // Test case: 2 is the majority element (appears 4 times out of 7)
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    
    int result = obj.majorityElement(nums);
    
    cout << "The majority element is: " << result << endl;
    
    return 0;
}