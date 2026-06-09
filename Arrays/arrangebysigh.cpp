#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0;
        int neg = 1;
        
        // This was a great shortcut you used to perfectly size the array
        vector<int> ans = nums; 
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                ans[pos] = nums[i];
                pos += 2;
            } else if(nums[i] < 0) {
                ans[neg] = nums[i];
                neg += 2;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    
    // Test case
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    
    vector<int> result = obj.rearrangeArray(nums);
    
    cout << "Rearranged Array:" << endl;
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}