#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int prefix_sum = 0;
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++){
            prefix_sum += nums[i];
            int remaining = prefix_sum - k;
            
            if(mpp.find(remaining) != mpp.end()){
                count += mpp[remaining];
            }
            mpp[prefix_sum]++;
        }
        return count;
    }
};

int main() {
    Solution obj;
    // Test case: Should output 2
    vector<int> nums = {1, 2, 3};
    int k = 3;
    
    int result = obj.subarraySum(nums, k);
    cout << "Total subarrays with sum " << k << " is: " << result << endl;
    
    return 0;
}