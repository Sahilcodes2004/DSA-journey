// Author: Sahil Jackson

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int maxi = 0;
        
        // Map stores <Prefix_Sum, Earliest_Index>
        // Using long long for the key to prevent overflow with massive arrays
        map<long long, int> mpp; 
        
        // Running sum from index 0 up to the current index 'i'
        long long prefix_sum = 0; 
        
        for(int i = 0; i < arr.size(); i++) {
            // Step 1: Add the current element to our running total
            prefix_sum += arr[i];
            
            // Step 2: Check if the subarray from the very beginning equals 'k'
            if(prefix_sum == k) {
                // Length is exactly the current index + 1 (e.g., index 2 means length 3)
                maxi = max(maxi, i + 1);
            }
            
            // Step 3: Look backward. Do we need to chop off a previous prefix to get 'k'?
            long long remaining = prefix_sum - k;
            
            // If the map contains that 'remaining' sum, it means the elements 
            // BETWEEN that old index and our current index 'i' add up to exactly 'k'.
            if(mpp.find(remaining) != mpp.end()) {
                // Calculate length: Current Index - Old Index
                int len = i - mpp[remaining];
                maxi = max(maxi, len);
            }
            
            // Step 4: Store the current prefix sum for future lookups
            // CRITICAL: Only store it if it does NOT exist yet (== mpp.end())
            // This ensures we keep the earliest possible index, maximizing subarray length.
            if(mpp.find(prefix_sum) == mpp.end()) {
                mpp[prefix_sum] = i;
            }
        }
        
        return maxi;
    }
};

int main() {
    // Define the test case vector and target K
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k = 15;
    
    Solution obj;
    int result = obj.longestSubarray(arr, k);
    
    cout << "The longest subarray length is: " << result << endl;
    
    return 0;
}